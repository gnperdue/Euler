import java.util.ArrayList;

public class PrimeNumbers {

  public boolean isPrime(long n) {
    if (1L == n) return true;
    if (2L == n) return true;
    if (3L == n) return true;

    long m = n - 1L;
    while (m > 1L) {
      if (0L == n % m) return false;
      m--;
    }

    return true;
  }

  public ArrayList<Long> listOfPrimes(long max) {
  
    ArrayList<Long> arr = new ArrayList<Long>();
    long val = 1L;
    while (val <= max) {
      if (isPrime(val)) {
        arr.add(val);
      }
      val++;
    }
    return arr;
  }

  public long nextPrime(long start) {

    long next = start + 1L;
    while ( !isPrime(next) ) next++;
    return next;
  }
}
