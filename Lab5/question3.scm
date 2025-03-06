(define (cube x)(* (* x x) x))

(define (cube-list list)
    (map cube list)
)
(display (cube-list '(1 2 3 4 5)))
(newline)