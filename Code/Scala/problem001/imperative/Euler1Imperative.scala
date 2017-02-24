
object Euler1Imperative {

  def main(args: Array[String]) {
    val answer: Int = 
      (2 until 1000).filter( x => (0==x%3) || (0==x%5) ).foldLeft(0) {_ + _}
    println("The sum is " + answer)
  }

}
