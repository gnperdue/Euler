
public class StringyNumbersTest {

  public static void main(String[] args) {

    StringyNumbersTest tester = new StringyNumbersTest();

    tester.testPalindromic();

  }

  public void testPalindromic() {

    StringyNumbers stringyNums = new StringyNumbers();

    int cand1 = 91019;
    int cand2 = 12321;
    int cand3 =    11;

    int cand4 = 91018;
    int cand5 = 13351;
    int cand6 =   811;

    System.out.println( cand1 + " is a palindromic number? " + 
        stringyNums.isPalindromic(cand1));
    System.out.println( cand2 + " is a palindromic number? " + 
        stringyNums.isPalindromic(cand2));
    System.out.println( cand3 + " is a palindromic number? " + 
        stringyNums.isPalindromic(cand3));
    System.out.println( cand4 + " is a palindromic number? " + 
        stringyNums.isPalindromic(cand4));
    System.out.println( cand5 + " is a palindromic number? " + 
        stringyNums.isPalindromic(cand5));
    System.out.println( cand6 + " is a palindromic number? " + 
        stringyNums.isPalindromic(cand6));

  }

}



