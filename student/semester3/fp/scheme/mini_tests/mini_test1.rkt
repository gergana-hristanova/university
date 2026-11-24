#lang racket

(define head car)
(define tail cdr)

; === Ex 1 ===

(define (max n)
  (define best (remainder n 10))
  (if (> (remainder n 10) best)
      (remainder n 10)
      (max (quotient n 10)))

(define (max-jump n)
  (define (loop n res)
    (if (< n 10)
        0
        (abs (max (max-jump (quotient n 10)) (remainder n 10)))))
  (loop n (remainder n 10)))

; === Ex 2 ===
; Рекурсивен процес

(define (has-root-in-interval? f a b)
  (< (* (f a) (f b)) 0))

(define (ilength a b) (- b a))

(define (solve f a b eps)
  (if (has-root-in-interval? f a (/ b 2))
      (if (> (ilength a b) eps)
          (solve f a (/ b 2) eps)
          b)
      (if (> (ilength a b) eps)
          (solve f (* a 2) b eps)
          a)))

; === Ex 3 ===
; Итеративен процес за window и window-average, ая рекурсивен за moving-average

(define (window lst k)
  (if (null? lst)
      '()
  (if (= k 1)
      (list (head lst))
      (cons (head lst) (window (tail lst) (- k 1))))))

(define (window-average lst k)
  (define (sum window res)
    (if (null? window)
        res
        (sum (tail window) (+ res (head window)))))
  (/ (sum (window lst k) 0) (length (window lst k))))

(define (moving-average lst k)
    (if (null? lst)
        '()
        (if (< (length lst) k)
           (window-average lst k)
           (cons (window-average lst k) (moving-average (tail lst) k)))))










