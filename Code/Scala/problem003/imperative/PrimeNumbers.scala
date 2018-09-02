package Euler3

object PrimeNumbers {

  private def prime(n:Long, m:Long): Boolean = (n,m) match {
    case (n, 1) => true
    case (n, m) => if (n % m == 0) false else prime (n, m - 1)
  }

  def isPrime(n: Long): Boolean = {
    prime( n, n-1 )
  }

  def isPrimeAlt(n: Long): Boolean = {
    var areAreNotPrime = for (m <- Stream range (2, n);
      comp = if (0 == n % m) false else true) yield comp
    /* var xx = areAreNotPrime takeWhile ( _ == false ) */
    if (areAreNotPrime.exists(_ == false)) false else true
  }

  def nextPrime(start: Long): Long = {
    var next = start + 1L;
    while ( !isPrime(next) ) { next = next + 1 }
    next
  }

  def listOfPrimes(max: Long): Array[Long] = {
    var arr = Array(1L)
    var num = 2L
    while (num < max) {
      if (isPrime(num)) arr = arr :+ num
      num = num + 1L
    }
    arr
  }

}
