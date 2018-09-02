package com.spintwo.projecteuler;

import java.util.*;
import java.util.TreeSet;
import java.util.Collections;

public class Euler004 {

  public void printAnswer() {

    Euler004 euler = new Euler004();
    StringyNumbers stringy = new StringyNumbers();

    TreeSet<Integer> candidates = euler.listOfProducts(900,999);
    for (int i: candidates) {
      if (stringy.isPalindromic(i)) {
        System.out.println("The largest Palindromic number is: " + i);
        break;
      }
    }
  }

  private TreeSet<Integer> listOfProducts(int low, int high) {
    NumCompare nc = new NumCompare();
    TreeSet<Integer> ts = new TreeSet<Integer>(nc);
    for (int i=low; i<=high; ++i) {
      for (int j=low; j<=high; ++j) {
        int product = i * j;
        ts.add(product);
      }
    }
    return ts;
  }

  class NumCompare implements Comparator<Integer> {
    public int compare(Integer one, Integer two) {
      return (two.compareTo(one));
    }
  }
}
