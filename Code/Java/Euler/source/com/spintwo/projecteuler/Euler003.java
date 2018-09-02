package com.spintwo.projecteuler;

import java.util.ArrayList;

public class Euler003 {

  private static long queryNumber = 600851475143L; 

  public void printAnswer() {

    PrimeNumbers calculator = new PrimeNumbers();

    System.out.println("Find the prime factors of " + 
        queryNumber);

    long startingPoint = 
      calculator.nextPrime( (long)Math.sqrt(1.0 * queryNumber) );
    System.out.println("Start with " + startingPoint);

    ArrayList<Long> primes = calculator.listOfPrimes(startingPoint);
    int nPrimes = primes.size();
    System.out.println("Found " + nPrimes + 
        " possible prime factors.");

    long largestPrimeFactor = primes.get(primes.size() - 1);
    for (int i=(nPrimes-1); i>=0; i--) {
      if (0 == queryNumber % primes.get(i)) {
        largestPrimeFactor = primes.get(i);
        break;
      }
    } 
    System.out.println("The largest prime factor is " + 
        largestPrimeFactor);
  }

}
