#!/usr/bin/env Rscript

is.prime.tailrec <- function(n, m) { 
  if (m == 1) TRUE else { if (n %% m == 0) FALSE else is.prime.tailrec(n, m - 1) }
}

is.prime <- function(n) { is.prime.tailrec(n, n - 1) }

next.prime <- function(n) {
  n <- n + 1
  while ( !is.prime(n) ) {
    n <- n + 1
  }
  n
}

list.of.primes <- function(n) {
  answer <- c(1)
  num <- 2
  while (num < n) {
    if (is.prime(num)) answer <- append(answer, num)
    num <- num + 1
  }
  answer
}

query.number <- 13195
#query.number <- 60085
#query.number <- 600851475143

answer <- c(1)

starting.point <-  next.prime( ceiling( sqrt( query.number ) ) )
primes <- list.of.primes(starting.point)

index <- length(primes)
largest.prime.factor <- primes[index]

while ( 0 != query.number %% largest.prime.factor ) {
  index <- index - 1
  largest.prime.factor <- primes[index]
}

print(largest.prime.factor)



