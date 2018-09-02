package com.spintwo.Euler

object Euler4 {

  import com.spintwo.Euler.PalindromicNumbers._

  private def getListOfProducts(low: Int, high: Int): List[Int] = {
    (for (m <- low to high; n <- low to high) 
      yield (m * n)).toList.sortWith(_ > _)
  }

  def main(args: Array[String]) {

    val candidates: List[Int] = getListOfProducts(900,999)
    val palindromic = 
    for (cand <- candidates; if isPalindromic(cand)) yield cand

    println("The largest palindromic number is " + palindromic.head)
  }

}

