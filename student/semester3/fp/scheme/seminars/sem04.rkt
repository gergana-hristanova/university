#lang racket

; stroke of genius tbh because those names are awful sorry IBM from the 50s
(define head car)
(define tail cdr)

; === Ex 0 ===

; Standard list functions: length, reverse, map, filter, foldr.
; In '(...) we can only have literals!
; (cons 1 (cons 2 (cons 3 (cons 4 '())))) -> '(1 2 3 4)

(define (length* lst)
  (if (null? lst)
      0
      (+ 1 (length* (tail lst)))))

(define (map* f lst)
  (if (null? lst)
      '()
      (cons (f (head lst))
            (map* f (tail lst)))))

; === Ex 1 ===
; Да се напишат (take n lst) и (drop n lst), който съответно взимат или премахват първите n елемента на списък.

(define (take n lst)
  (if (= n 0)
      '()
      (if (= n 1)
      (cons (head lst) '())
      (cons (head lst) (take (- n 1) (tail lst))))))

(define (drop n lst)
  (if (= n 0)
      lst
      (if (= n 1)
      (tail lst)
      (drop (- n 1) (tail lst)))))

; === Ex 2 ===
; (all? p? lst) и (any? p? lst)

(define (all? p? lst)
  (if (null? lst)
      #t
      (if (not (p? (head lst)))
          #f
          (all? p? (tail lst)))))

(define (any? p? lst)
  (if (null? lst)
      #f
      (if (p? (head lst))
          #t
          (any? p? (tail lst)))))

; === Ex 3 ===
; (zip '(1 2 3 4) '(#t #f #f)) -> '((1 . #t) (2 . #f) (3 . #f))

(define (zip lst1 lst2)
  (if (or (null? lst1) (null? lst2))
      '()
      (cons (cons (head lst1) (head lst2)) (zip (tail lst1) (tail lst2)))))

; === Ex 4 ===
; (zipWith + '(1 2 3 4) '(7 10 12)) -> '(8 12 15)

(define (zipWith f lst1 lst2)
    (if (or (null? lst1) (null? lst2))
      '()
      (cons (f (head lst1) (head lst2)) (zipWith f (tail lst1) (tail lst2)))))

; === Ex 5 ===
; Да се напише функция (sorted? lst), която проверява дали списък е сортиран в ненамаляващ ред.

(define (sorted? lst)
  (if (or (null? lst) (null? (tail lst)))
      #t
      (if (> (head lst) (head (tail lst)))
          #f
          (sorted? (tail lst)))))

; + a version that is only one boolean expression

(define (sorted?? lst)
  (or (null? lst) (null? (tail lst))
      (and (not (> (head lst) (head (tail lst))))
          (sorted? (tail lst)))))

; === Ex 7 ===
; (uniques '(1 2 2 "iei" 1 3 "iei" 'oops)) -> '(1 2 "iei" 3 'oops) ; подредбата в резултата няма значение

(define (contains? lst el)
  (if (null? lst)
      #f
      (if (equal? (head lst) el)
          #t
          (contains? (tail lst) el))))

(define (uniques lst)
  (if (null? lst)
      '()
      (if (not (contains? (tail lst) (head lst)))
          (cons (head lst) (uniques (tail lst)))
          (uniques (tail lst)))))

; === Ex 8 ===
; (insert 5 '(1 4 10)) -> '(1 4 5 10)
; (insert 12 '(1 4 10)) -> '(1 4 10 12)

(define (insert el lst)
  (if (null? lst)
      (cons el '())
      (if (<= el (head lst))
          (cons el (cons (head lst) (tail lst)))
          (cons (head lst) (insert el (tail lst))))))

; === Ex 9 ===
; (insertion-sort '(4 3 6 2 1 8 10)) -> '(1 2 3 4 6 8 10)

(define (insertion-sort lst)
  (if (null? lst)
      '()
      (insert (head lst) (insertion-sort (tail lst)))))