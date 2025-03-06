(define (fact_recursive a b ) 
  (if (equal? a 0) 
        b
       (fact_recursive (- a 1) (* b a) )
    ) )

(define (fact n )
  (fact_recursive n 1 )
)

(display (fact 7))
(newline)