
public class StringyNumbers {

  public boolean isPalindromic(int number) {
  
    String stringyNumber = String.valueOf(number);
    String reversedNumber = new StringBuffer(stringyNumber).reverse().toString();
    return stringyNumber.equals(reversedNumber);

  }

}
