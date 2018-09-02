import java.util.ArrayList;

public class Euler002 {

  private ArrayList<Long> fiboList(long n) {
    ArrayList<Long> arr = new ArrayList<Long>();
    arr.add(1L);
    arr.add(1L);
    int i = 2;
    while ( arr.get( arr.size()-1 ) < n ) {
      arr.add( arr.get(i - 1) + arr.get(i - 2) );
      i++;
    }
    return arr;
  }

  public static void main(String[] args) {

    ArrayList<Long> fibos = new Euler002().fiboList(4000000);
    long sum = 0L;
    for (long i: fibos) {
      System.out.print( i );
      if (0L == i%2L) sum += i;
      System.out.println( "  " + sum );
    }
    System.out.println( "The sum is " + sum );
  }

}
