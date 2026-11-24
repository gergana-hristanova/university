#lang racket

;; често използвани функции
(define (id x) x)
(define (1+ x) (+ x 1))
(define (compose f g) (lambda (x) (f (g x))))

;; натрупване от по-висок ред
(define (accumulate op nv a b term next)
  (if (> a b) nv
      (op (term a) (accumulate op nv (next a) b term next))))

;; функции от по-висок ред за списъци
(define (filter p? l)
  (cond ((null? l) l)
        ((p? (car l)) (cons (car l) (filter p? (cdr l))))
        (else (filter p? (cdr l)))))

(define (foldr op nv l)
  (if (null? l) nv
      (op (car l) (foldr op nv (cdr l)))))

(define (foldl op nv l)
  (if (null? l) nv
      (foldl op (op nv (car l)) (cdr l))))

(define (foldr1 op l)
  (if (null? (cdr l)) (car l)
      (op (car l) (foldr1 op (cdr l)))))

(define (foldl1 op l)
  (foldl op (car l) (cdr l)))

(define (search p l)
  (and (not (null? l)) (or (p (car l)) (search p (cdr l)))))

(define (all? p? l)
  (not (search (lambda (x) (not (p? x))) l)))

;; функции за потоци
(define the-empty-stream '())

(define-syntax cons-stream
  (syntax-rules () ((cons-stream h t) (cons h (delay t)))))

(define head-stream car)

(define (tail-stream s) (force (cdr s)))

(define empty-stream? null?)

(define (map-stream f s)
  (cons-stream (f (head-stream s)) (map-stream f (tail-stream s))))

(define (filter-stream p? s)
  (if (p? (head-stream s))
      (cons-stream (head-stream s) (filter-stream p? (tail-stream s)))
      (filter-stream p? (tail-stream s))))

(define (zip-streams op s1 s2)
  (cons-stream (op (head-stream s1) (head-stream s2)) (zip-streams op (tail-stream s1) (tail-stream s2))))

(define (tree? t)
  (or (null? t)
      (and (list? t)
           (= (length t) 3))
           (tree? (cadr t))
           (tree? (caddr t))))
(define empty-tree '())
(define (make-tree root left right) (list root left right))      ; не искаме просто (define make-tree list) - защо?
(define (make-leaf root) (make-tree root empty-tree empty-tree)) ; за удобство
(define root-tree car)
(define left-tree cadr)
(define right-tree caddr)
(define empty-tree? null?)

; === Ex 1 ===

(define (filter-by-position n p?)
  (define (loop n p? count mult res)
    (cond [(<= n 0) res]
          [else (if (p? count)
                    (loop (quotient n 10) p? (+ 1 count) (* 10 mult) (+ (* mult (remainder n 10)) res))
                    (loop (quotient n 10) p? (+ 1 count) mult res))]))
  (loop n p? 1 1 0))

; === Ex 2 ===

(define (num-len n)
  (define (loop n count)
    (if (= n 0) count
    (if (< n 10) (+ 1 count)
        (loop (quotient n 10) (+ 1 count)))))
  (loop n 0))

(define (digit-power-position n)
  (define (loop n pos res)
    (cond [(<= n 0) res]
          [else (let ([curr-res (expt (remainder n 10) pos)])
                  (loop (quotient n 10) (+ 1 pos) (+ res (* (expt 10 (num-len res)) curr-res))))]))
  (loop n 1 0))

; === Ex 3 ===

;(maximum-even-nodes-sum '(1 (4 () ()) (6 (3 () ()) (-4 () ())))) → (1 6 3)
;(maximum-even-nodes-sum '(1 (4 () ()) (6 (-2 () ()) (-4 () ())))) → (1 6)

(define (height t)
  (if (empty-tree? t) 0
      (+ 1 (max (height (left-tree t))
                (height (right-tree t))))))

(define (even-and-positive? x)
  (and (even? x) (positive? x)))

(define (even-sum list)
  (foldl + 0 (filter even? list)))

(define (maximum-even-nodes-sum t)
  (cond [(empty-tree? t) '()]
        [(= 1 (height t)) (list (root-tree t))]
        [else (let ([left-mens (maximum-even-nodes-sum (left-tree t))]
                    [right-mens (maximum-even-nodes-sum (right-tree t))])
                (if (> (even-sum left-mens) (even-sum right-mens))
                    (cons (root-tree t) left-mens)
                    (cons (root-tree t) right-mens)))]))

; === Ex 4 ===

(define (length lst)
  (cond [(null? lst) 0]
        [(+ 1 (length (cdr lst)))]))

(define (prod-odds list)
  (foldl * 1 (filter odd? list)))

(define (get-longer-list l1 l2)
  (if (> (length l1) (length l2)) l1 l2))

(define (minimum-odd-nodes-prod t)
  (cond [(empty-tree? t) '()]
        [(= 1 (height t)) (list (root-tree t))]
        [(empty-tree? (left-tree t)) (minimum-odd-nodes-prod (right-tree t))]
        [(empty-tree? (right-tree t)) (minimum-odd-nodes-prod (left-tree t))]
        [else (let* ([left-monp (minimum-odd-nodes-prod (left-tree t))]
                     [right-monp (minimum-odd-nodes-prod (right-tree t))]
                     [left-prod-odds (prod-odds left-monp)]
                     [right-prod-odds (prod-odds right-monp)])
                (cond [(= left-prod-odds right-prod-odds)
                       (cons (root-tree t) (get-longer-list left-monp right-monp))]
                      [(< left-prod-odds right-prod-odds)
                       (cons (root-tree t) left-monp)]
                      [else (cons (root-tree t) right-monp)]))]))

(define (root-paths t)
  (if (null? t)
      '()
      (let* ([root (car t)]
             [left-paths (root-paths (cadr t))]
             [right-paths (root-paths (caddr t))]
             [sub-paths (append left-paths right-paths)])
        (cons (list root)
              (map (lambda (p) (cons root p)) sub-paths)))))

; === Ex STREAM ===

(define (stream-from n)
  (cons-stream n (stream-from (+ n 1))))

(define (stream-take s n)
  (if (or (= n 0) (empty-stream? s)) '()
      (cons (head-stream s) (stream-take (tail-stream s) (- n 1)))))

(define (stream-ref s n)
  (if (or (= n 0) (empty-stream? (tail-stream s)))
      (head-stream s)
      (stream-ref (tail-stream s) (- n 1))))

(define (stream-sum s n)
  (define (loop s n res)
    (if (or (empty-stream? (tail-stream s)) (= n 0))
        (+ res (head-stream s))
        (loop (tail-stream s) (- n 1) (+ res (head-stream s)))))
  (loop s n 0))

(define (stream-iterate f x)
  (cons-stream x (stream-iterate f (f x))))

(define (fib-stream)
  (define (fib-gen a b)
    (cons-stream a (fib-gen b (+ a b))))
  (fib-gen 0 1))

; ====

(define (subsets lst)
  (cond [(null? lst) (list '())]
        [else (let ([curr-subsets (subsets (cdr lst))])
         (append (map (lambda (sub) (cons (car lst) sub)) curr-subsets) curr-subsets))]))

(define (rotations lst)
  (define (loop lst count res)
    (cond [(null? lst) (list '())]
          [(<= count 0) (append (cdr lst) (list (car lst))) res]
          [else (let [(curr-rot (append (cdr lst) (list (car lst))))]
           (loop curr-rot (- count 1) (append res (list curr-rot))))]))
  (loop lst (length lst) '()))

(define (remove-one lst x)
  (cond [(null? lst) '()]
        [(equal? x (car lst)) (cdr lst)]
        [else (cons (car lst) (remove-one (cdr lst) x))]))

(define (permutations lst)
  (cond [(null? lst) (list '())]
        [else
         (apply append
                (map (lambda (elem)
                       (let ([others (permutations (remove-one lst elem))])
                         (map (lambda (x) (cons elem x)) others)))
                     lst))]))

(define head car)
(define tail cdr)

(define a1
  (list (list
         (cons (cons 'A #\b) 'B)
         (cons (cons 'B #\a) 'A))
        'A
        (list 'A)))

;(apply-delta (head a1) 'B #\a) -> 'A
;(apply-delta (head a1) 'B #\m) -> #f

(define (apply-delta delta state symb)
  (cond [(null? delta) #f]
        [else (let ([curr (head delta)])
           (or (and (equal? (head (head curr)) state)
                    (equal? (tail (head curr)) symb)
                    (tail curr))
               (apply-delta (tail delta) state symb)))]))















