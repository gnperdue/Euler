
object Euler2Imperative {

  def genFibo(max: Int): Array[Int] = {
    var fibo = Array(1,1)
    var i = 2
    while ( fibo( fibo.length-1 ) < max ) {
      fibo = fibo :+ fibo(i-1) + fibo(i-2)
      i += 1
    }
    fibo
  }

  def main(args: Array[String]) {
    
    val fibos = genFibo( 4000000 )
    var sum: Int = 0
    for (fibo <- fibos; if (0 == fibo%2) ) 
      sum += fibo
    println("The sum is " + sum)

  }

}
