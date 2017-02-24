def modsum(num:Int) = { ( for (n <- 1 to 999; if (n%num==0)) yield n).sum }
lazy val euler = modsum(3) + modsum(5) - modsum(15)
println(euler)


