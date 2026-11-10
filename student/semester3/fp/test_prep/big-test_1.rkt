#lang racket

(define head car)
(define tail cdr)

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
    (if (<= n 0) length
        (if (< n 10)
        1
        (loop (quotient n 10) (+ 1 length)))))
  (loop n 0))

(define (multiply-by-position n)
  (define (loop n count res)
    (cond [(= n 0) res]
          [else (let ([last-digit-res (* (remainder n 10) count)])
           (loop (quotient n 10) (+ 1 count) (+ (* (expt 10 (num-length last-digit-res)) res) last-digit-res)))]))
  (loop n 1 0))




