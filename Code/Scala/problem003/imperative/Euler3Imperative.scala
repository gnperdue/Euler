package Euler3


object Euler3Imperative {

  import Euler3.PrimeNumbers._

  /* val queryNumber = 13195 */
  val queryNumber = 600851475143L

  def main(args: Array[String]) {

    println("Find the largest prime factor of " + queryNumber)

    val startingPoint: Long = 
    nextPrime( (Math.sqrt(queryNumber)).toLong )
    println("Start with " + startingPoint)

    val primes = listOfPrimes(startingPoint)
    val nPrimes = primes.length
    println("Found " + nPrimes + " possible prime factors.")

    var index = primes.length-1
    var largestPrimeFactor: Long = primes( index )
    while (0 != queryNumber % largestPrimeFactor) {
      index = index - 1
      largestPrimeFactor = primes( index )
    }
    println("The larges prime factor is " + 
      largestPrimeFactor)

  }

}
