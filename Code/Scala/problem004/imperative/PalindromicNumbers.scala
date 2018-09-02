package com.spintwo.Euler

object PalindromicNumbers {

  def isPalindromic(number: Int): Boolean = {
    val stringyNumber: String = String.valueOf(number)
    stringyNumber.equals(
      new StringBuffer(stringyNumber).reverse().toString())
  }

}

