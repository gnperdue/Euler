#!/usr/bin/env Rscript

fibo <- function(n) if (n == 0 || n == 1) 1 else (fibo(n-1) + fibo(n - 2))

answer <- 0

counter <- 2
fib <- fibo(counter)
answer <- answer + fib
while ( fib < 4000000 ) {
  counter <- counter + 1
  fib <- fibo(counter)
  if (fib %% 2 == 0) answer <- answer + fib
}

print(answer)

# > source("./euler002.R")
# > fibo(0)
# [1] 1
# > fibo(1)
# [1] 1
# > fibo(2)
# [1] 2
# > fibo(3)
# [1] 3
# > fibo(4)
# [1] 5
# > fibo(5)
# [1] 8
# > fibo(10)
# [1] 89
# > fibo(9)
# [1] 55
# > fibos <-c(fibo(2))
# > typeof(fibos)
# [1] "double"
# > class(fibos)
# [1] "numeric"
# > ?append
# > append(fibos, fibo(5))
# [1] 2 8

