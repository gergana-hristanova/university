#lang racket

;; често използвани функции
(define (id x) x)
(define (1+ x) (+ x 1))
(define (square x) (* x x))
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

(define head car)

(define (tail s) (force (cdr s)))

(define empty-stream? null?)

(define (map-stream f s)
  (cons-stream (f (head s)) (map-stream f (tail s))))

(define (filter-stream p? s)
  (if (p? (head s))
      (cons-stream (head s) (filter-stream p? (tail s)))
      (filter-stream p? (tail s))))

(define (zip-streams op s1 s2)
  (cons-stream (op (head s1) (head s2)) (zip-streams op (tail s1) (tail s2))))

; === Ex 1 ===

(define (subsets lst)
  (if (null? lst)
      (list '())
      (let ([sub-subsets (subsets (tail lst))])
        (append sub-subsets (map (lambda (x) (cons (head lst) x)) sub-subsets)))))

; === Ex 2 ===

(define (head-to-back lst)
  (append (tail lst) (list (head lst))))

(define (rotations lst)
  (if (null? lst)
      (list '())
      (map (lambda (x) (head-to-back x)) lst)))

; === Ex 1 ===

(define (num-length n)
  (define (loop n length)
    (if (< n 10)
        (+ 1 length)
        (loop (quotient n 10) (+ 1 length))))
  (loop n 0))

(define (multiply-by-position n)
  (define (loop n count res)
    (cond [(= n 0) res]
          [else (let ([last-digit-res (* (remainder n 10) count)])
           (loop (quotient n 10) (+ 1 count) (+ (* (expt 10 (num-length last-digit-res)) res) last-digit-res)))]))
  (loop n 1 0))

; === Ex 2 ===

(define (num-len x)
  (if (< x 10)
      1
      (+ 1 (num-len (quotient x 10)))))

(define (sum-with-position n)
  (define (loop n count res len)
    (if (<= n 0)
        res
        (let ([curr-res (+ count (remainder n 10))])
          (loop (quotient n 10)
                (+ 1 count)
                (+ (* curr-res (expt 10 len)) res)
                (+ len (num-len curr-res))))))
  (loop n 1 0 0))

; === Ex 3 ===

(define (max-lst lst)
  (apply max lst))

(define (min-lst lst)
  (apply min lst))

(define (max-func f I)
  (max-lst (map f I)))

(define (max-row fr I)
  (max-lst (map (lambda (f) (max-func f I)) fr)))

(define (minmax fm I)
  (min-lst (map (lambda (fr) (max-row fr I)) fm)))

















