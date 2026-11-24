#lang racket

; === Ex 1 ===
; $$\frac{15 + 21 + \frac{3}{15} + (7 - 2 \cdot 2)}{16}$$

(/ (+ 15 21 3/15 (- 7 (* 2 2))) 16)

; === Ex 2 ===
; Напишете функция (increasing? n), която проверява дали цифрите на дадено
; естествено число n са в строго нарастващ ред, четени отляво-надясно
; (напр. (increasing? 12489) -> #t, (increasing? 4456) -> #f).

(define (increasing? n)
  (cond [(= n 0) #t]
        [(> (quotient (remainder n 100) 10) (remainder n 10)) #f]
        [else (increasing? (quotient n 10))]))

; === Ex 3 ===
; Напишете функция (toBinary n), която превръща дадено естествено число n в
; двоична бройна система, генерирайки итеративен процес (напр. (toBinary 42) -> 101010).

(define (toBinary n)
  (define (loop n res count)
    (if (= n 0)
        res
        (loop (quotient n 2) (+ res (* (remainder n 2) (expt 10 count))) (+ count 1))))
  (loop n 0 0))

; === Ex 4 ===
; Напишете функция (fast-pow x n): [n е четно: (x^n = (x^(n/2))^2, в противен случай: x^n = x*(x^(n/2))^2].

(define (sq n) * n n)

(define (fast-pow x n)
  (cond [(= n 0) 1]
        [(even? n) (sq (fast-pow x (/ n 2)))]
        [else (* x (fast-pow (sq x) (/ (- n 1) 2)))]))

; gave up on it

; === Ex 5 ===
; Напишете функция от по-висок ред (flip f), която приема двуместна
; функция f и връща нова функция с разменени места на нейните два аргумента. (Пример: ((flip -) 4 10) -> 6)

(define (flip f)
  (lambda (x y) (f y x)))

; Напишете функция от по-висок ред (repeat n f), която връща
; n-кратната композиция на едноместната функция f.
; (Пример: ((repeat 5 (lambda (x) (+ x 1))) 10) -> 15) 

(define (accumulate op nv a b term next)
  (if (> a b)
      nv
      (op (term a) (accumulate op nv (next a) b term next))))

(define (compose f g) (lambda (i) (g (f i))))

(define (id i) i)

(define (++ n) (+ n 1))

(define (repeat n f)
  (accumulate compose id 1 n (lambda (i) f) ++))

; === Ex 6 ===
; Напишете функция (twist k f g) за четно число $k$, която връща функция,
; еквивалентна на алтернативното прилагане $f(g(f(g(...(x)...))))$,
; където общият брой извиквания на $f$ и $g$ е точно $k$. 

(define (twist k f g)
  (accumulate compose id 1 (/ k 2) (lambda (i) (compose f g)) ++))

; === Ex 7 ===
; Напишете функция (argmax f a b), която по даден непразен
; целочислен интервал $[a; b]$ намира онова число $x \in [a; b]$,
; за което стойността $f(x)$ е максимална. (Пример: (argmax (lambda (x) (remainder x 7)) 40 45) -> 41)   

(define (max* x y)
  (if (> x y) x y))

(define (argmax f a b)
  (if (> a b)
      b
      (if (= (accumulate max* (f a) a b (lambda (i) (f i)) ++) (f a))
      a
      (argmax f (++ a) b))))
  
; === Ex 8 ===
; Напишете функции (take n lst) и (drop n lst),
; които съответно вземат или премахват първите $n$ елемента от даден списък.

(define head car)
(define tail cdr)

(define (take n list)
  (if (= n 0)
      '()
      (if (= n 1)
          (cons (head list) '())
          (cons (head list) (take (- n 1) (tail list))))))

(define (drop n list)
  (if (= n 0)
      list
      (if (= n 1)
          (tail list)
          (drop (- n 1) (tail list)))))

; === Ex 9 ===
; (zipWith + '(1 2 3 4) '(7 10 12)) -> '(8 12 15)

(define (zipWith op l1 l2)
  (if (or (null? l1) (null? l2))
      '()
      (cons (op (head l1) (head l2)) (zipWith op (tail l1) (tail l2)))))

; === Ex 10 ===
; Напишете функция (uniques lst), която приема списък и връща нов списък,
; съдържащ само уникалните му елементи (без повторения).

(define (contains? list el)
  (if (null? list)
      #f
      (if (= (head list) el)
          #t
          (contains? (tail list) el))))

(define (headtail list) (head (tail list)))

(define (uniques list)
  (if (null? list)
      '()
      (if (not (contains? (tail list) (head list)))
          (cons (head list) (uniques (tail list)))
          (uniques (tail list)))))

; === Ex 18 ===
; Дефинирайте помощна функция (insert el list), която вмъква el
; на правилното място в вече сортиран в ненамаляващ ред списък list.
; Дефинирайте (insertion-sort lst), която сортира даден списък.

(define (insert el lst)
  (if (null? lst)
      (list el)
      (if (<= el (head lst))
          (cons el lst)
          (cons (head lst) (insert el (tail lst))))))

(define (insertion-sort lst)
  (if (null? lst)
      '()
      (insert (head lst) (insertion-sort (tail lst)))))

; === Ex 19 ===
; (sublists '(1 2)) -> '(() (2) (1) (1 2))

(define (sublists lst)
  (foldr (lambda (x acc)
           (append acc (map (lambda (sub) (cons x sub)) acc)))
         '(())
         lst))


