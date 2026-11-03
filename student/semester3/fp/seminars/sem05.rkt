#lang racket

(define head car)
(define tail cdr)

; === Ex 0 ===
; Шест различни начина за решение на задачата за uniques.

; 1. Рекурсивно - в миналия семинар е разглеждано

; 2. Итеративно

(define (uniques* lst)
  (define (loop lst res)
    (cond [(null? lst) res]
          [(member (head lst) res) (loop (tail lst) res)]
          (else (loop (tail lst) (cons (head lst) res)))))
  (loop lst '()))

; 3. По-сложно рекурсивно. В първото условие на cond смятаме два пъти uniques** ненужно

; (define (uniques** lst)
;   (cond [(null? lst) (head lst) (uniques** (tail lst)))
;        (uniques** (tail lst))]
;        [else (cons (head lst) (uniques** (tail lst)))]))

; 4. Поправка на предишното с помощна функция

(define (cons-if-not x lst)
  (if (member x lst)
      lst
      (cons x lst)))

(define (uniques*** lst)
  (if (null? lst)
      '()
      (cons-if-not (head lst) (uniques*** (tail lst)))))

; 5. Чрез foldr

(define (uniques**** lst)
  (foldr cons-if-not '() lst))

; 6. Чрез filter

(define (uniques***** lst)
  (cond [(null? lst) '()]
        (else (cons (head lst) (uniques*****
                                (filter (lambda (x) (not (equal? x (head lst))))
                                        (tail lst)))))))

; === Ex 1 ===

; Вече решена 6 пъти по-горе.

; === Ex 2 ===

(define (insert val lst)
  (cond [(null? lst) (list val)]
        [(<= val (head lst)) (cons val lst)]
        (else (cons (head lst) (insert val (tail lst))))))

; === Ex 4 ===

;(define (interval-length interval)
;  (- (tail lst) (head lst)))

;(define (max-by-length il)
;  (define (loop lst res)
;    )
;    (loop (tail lst) (head lst)))

; (define (sub-interval? smalli bigi)
;  (and (>= (head smalli) (head bigi)) (<= (tail smalli) (tail bigi))))

;(define (longest-interval-subsets il)
;  (define best (max-by-length lst))
;  (filter (lambda (i) (sub-interval? i best)) lst))