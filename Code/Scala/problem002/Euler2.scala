val fibo: (Int => Int) = (n:Int) => n match {
  case 0 => 1
  case 1 => 1
  case n => fibo(n-1) + fibo(n-2)
}

val test1 = (0 until 10).toList.map(fibo)
val test2 = (0 until 10).toList.map(fibo).filter(_ < 10)
val test3 = (0 until 10).toList.map(fibo).filter(_ < 10).filter(_ % 2 == 0)
val test4 = (0 until 10).toList.map(fibo).filter(_ < 10).filter(_ % 2 == 0).sum

val sfib: Stream[Int] = Stream.cons(0,
  Stream.cons(1, sfib.zip(sfib.tail).map(t => t._1 + t._2)))

