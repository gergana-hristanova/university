#lang racket

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

(define test-tree
  (make-tree 10
             (make-tree 7
                        (make-leaf 10)
                        (make-leaf 2))
             (make-tree 3
                        (make-tree 4
                                   (make-leaf 1)
                                   (make-leaf 2))
                        empty-tree)))

(define bst-tree
  (make-tree 10
             (make-tree 5
                        (make-leaf 2)
                        (make-tree 7
                                   empty-tree
                                   (make-leaf 8)))
             (make-tree 15
                        (make-leaf 12)
                        (make-leaf 20))))


; === Ex 1 ===

(define (height t)
  (if (empty-tree? t) 0
      (+ 1 (max (height (left-tree t))
                (height (right-tree t))))))

; === Ex 2 ===

(define (get-level n t)
  (cond [(empty-tree? t) '()]
        [(= n 0) (list (root-tree t))]
        [else (append (get-level (- n 1) (left-tree t))
                      (get-level (- n 1) (right-tree t)))]))

; === Ex 3 ===

(define (longer-subtree t)
  (if (> (height (left-tree t)) (height (right-tree t)))
      (left-tree t)
      (right-tree t)))

(define (find-longest-path t)
  (cond [(empty-tree? t) '()]
        [(= 1 (height t)) (list (root-tree t))]
        [else (append (list (root-tree t)) (find-longest-path (longer-subtree t)))]))

; === Ex 4 ===

(define (tree-map f t)
  (cond [(empty-tree? t) '()]
        [(= 1 (height t)) (make-leaf (f (root-tree t)))]
        [else (make-tree (f (root-tree t)) (tree-map f (left-tree t)) (tree-map f (right-tree t)))]))

; === Ex 5 ===

(define (tree->list t)
  (cond [(empty-tree? t) '()]
        [else (append (tree->list (left-tree t)) (list (root-tree t)) (tree->list (right-tree t)))]))

; === Ex 6 ===

(define (bst-insert val t)
  (cond [(empty-tree? t) (make-leaf val)]
        [(<= val (root-tree t)) (make-tree (root-tree t) (bst-insert val (left-tree t)) (right-tree t))]
        [else (make-tree (root-tree t) (left-tree t) (bst-insert val (right-tree t)))]))

; === Ex 7 ===

(define (tree-sort lst)
  (tree->list (foldl bst-insert empty-tree lst)))

; === Ex 8 ===

(define (valid-bst? t)
  (equal? (tree->list t) (tree-sort (tree->list t))))

; === Ex 9 ===

(define (prune t)                                    
  (cond [(or (empty-tree? t) (= 1 (height t))) '()]
        [else (make-tree (root-tree t) (prune (left-tree t)) (prune (right-tree t)))]))

; === Ex 10 ===

(define (bloom t)
  (cond [(empty-tree? t) '()]
        [(= 1 (height t)) (make-tree (root-tree t) (root-tree t) (root-tree t))]
        [else (make-tree (root-tree t) (bloom (left-tree t)) (bloom (right-tree t)))]))

; === Ex 11 ===

(define (average x y)
  (/ (+ x y) 2))

(define (avg t)
  (define (get-avg tr)
    (average (apply max (tree->list tr)) (apply min (tree->list tr))))
  (cond [(empty-tree? t) '()]
        [else (make-tree (get-avg t) (avg (left-tree t)) (avg (right-tree t)))]))

; === Ex 12 ===

(define (same-as-code t)
  (define (helper curr-t curr-code res)
    (cond [(empty-tree? curr-t) res]
          [(= (root-tree curr-t) curr-code)
           (let ([curr-res (append res (list (root-tree curr-t)))])
           (let ([left-res (helper (left-tree curr-t) (* 2 curr-code) curr-res)])
             (helper (right-tree curr-t) (+ 1 (* 2 curr-code)) left-res)))]
          [else (let ([left-res (helper (left-tree curr-t) (* 2 curr-code) res)])
             (helper (right-tree curr-t) (+ 1 (* 2 curr-code)) left-res))]))
  (helper t 1 '()))







