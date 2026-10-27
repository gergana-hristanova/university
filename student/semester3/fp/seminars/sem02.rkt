#lang racket

; === Ex 1 ===

(define (sum_interval a b)
  (define (loop sum i)
    (if (> i b)
     sum
    (loop (+ sum i) (+ i 1))))
  (loop 0 a))

; === Ex 2 ===

 (define (count_digit d n)
  (define (loop n count)
    (if (= n 0)
        count
        (if (= (remainder n 10) d)
            (loop (quotient n 10) (+ count 1))
            (loop (quotient n 10) count))))
   (loop n 0))

; === Ex 3 ===

(define (reverse_digit n)
  (define (loop n res)
    (if (= n 0)
    res
    (loop (quotient n 10) (+ (* res 10) (remainder n 10)))))
  (loop n 0))

; === Ex 4 ===
; Да се напише функция, която намира сумата на всички делители на дадено естествено число.

(define (divisors_sum n)
  (define (loop i sum)
    (if (> i n)
        sum
        (if (= 0 (remainder n i))
            (loop (+ i 1) (+ i sum))
            (loop (+ i 1) sum))))
  (loop 1 0))

; === Ex 5 ===
; Да се напише функци, която проверява дали даден число е съвършено.
; Съвършени числа са тези, за които сумата на всичките им делители (без самото число) е равна на същото число.

(define (perfect? n)
  (= (- (divisors_sum n) n) n))

; === Ex 6 ===
; Да се напише функция, която проверява дали дадено число е просто.

(define (prime? n)
  (define (loop i)
    (if (= 0 (remainder n i))
        #f
        (if (= (- n 1) i)
            #t
            (loop (+ i 1)))))
  (if (= n 1)
      #f
  (loop 2)))

; === Ex 7 ===
; Да се напише функция (increasing? n), която проверява дали цифрите на дадено естествено число са в нарастващ ред.

(define (increasing? n)
  (define (loop n d1 d2)
    (if (> n 100)
        (<= d1 d2)
             ;   step             ; digit 1                 ; digit 2
        (loop (quotient n 10) (remainder (quotient n 10) 10) (quotient n 10))))
  (loop n (remainder (quotient n 10) 10) (remainder n 10)))

; === Ex 8 ===
; Да се напише функция, която превръща дадено естествено число в двоична бройна система.

(define (toBinary n)
  (define (loop n res counter)
    (if (= n 0)
        res
        (loop (quotient n 2) (+ res (* (remainder n 2) (expt 10 counter))) (+ 1 counter))))
  (loop n 0 0))

; === Ex 9 ===
; Да се напише функция, която превръща дадено естествено число от двоична в десетична бройна система:

(define (toDecimal bin)
  (define (loop bin dec counter)
    (if (= bin 0)
        dec
        (loop (quotient bin 10) (+ dec (* (remainder bin 10) (expt 2 counter))) (+ 1 counter))))
  (loop bin 0 0))

; === Ex 10 ===
; Напишете функция, която пресмята x^n бързо [n е четно: (x^n = (x^(n/2))^2, в противен случай: x^n = x*(x^(n/2))^2].

(define (square n) (* n n))

(define (qexpt x n)
  (cond [(= n 0) 1]
        [(= 0 (remainder n 2)) (square (qexpt x (/ n 2)))]
        [else (* x (qexpt (square x) (/ (- n 1) 2)))]))   