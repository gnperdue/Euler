
object Euler1 extends App {

  def getMod(n: Int): Int = n match {
    case n if (0 == n % 3)  =>  n
    case n if (0 == n % 5)  =>  n
    case _ => 0
  }

  def getEuler1(n: Int): Int = {
    (1 to n).toList.map(getMod).sum
  }
}
