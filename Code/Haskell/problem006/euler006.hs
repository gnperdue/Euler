
euler6 max = squareSum max - sumSquares max

squareSum max = s * s where s = sum [1..max]

sumSquares max = foldr (\x acc -> x*x + acc) 0 [1..max]

main = print $ euler6 100
