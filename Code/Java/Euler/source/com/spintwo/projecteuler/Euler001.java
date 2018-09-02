package com.spintwo.projecteuler;

public class Euler001 {

  private int compute() {
    int sum = 0;
    for (int i = 2; i < 1000; ++i) {
      if ( (0 == i%3) || (0 == i%5) ) sum += i;
    }
    return sum;
  }

  public void printAnswer() {
    int sum = compute();
    System.out.println("The sum is " + sum);
  }

}
