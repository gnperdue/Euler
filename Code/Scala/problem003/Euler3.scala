
val isPrime: ((Int, Int) => Boolean) = (n:Int,m:Int) => (n,m) match {
  case (n,1) => true
  case (n,m) => if (n % m == 0) false else isPrime (n, m - 1)
}

val isPrimeAlt: (Long => Boolean) = (n:Long) => {
  var areAreNotPrime = for (m <- Stream range (4, n);
    comp = if (0 == n % m) false else true) yield comp
  var isIsNotPrime = areAreNotPrime takeWhile ( _ == false )
  if (0 == isIsNotPrime.toList.length) false else true
} 

var n = 11
var areAreNotPrime = for (m <- Stream range (2, n);
  comp = if (0 == n % m) false else true) yield comp
var answer = if (areAreNotPrime.exists(_ == false)) false else true


