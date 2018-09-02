targetVal :: Int
targetVal = 500

main = do writeFile "euler012.txt" $ show (euler 1)

-- too slow...
euler12 n = takeWhile ((/= n) . snd) $ map (nTriangDivis) [1..]

euler :: Integral a => a -> (a, Int)
euler n = if snd ntd == targetVal
          then ntd 
          else euler (n + 1)
            where ntd = nTriangDivis n

nTriangDivis :: Integral a => a -> (a, Int)
nTriangDivis n = (triangularNumber n, length $ factors $ triangularNumber n)

triangularNumber :: (Integral a) => a -> a
triangularNumber n = sum [1..n]

factors :: (Integral a) => a -> [a]
factors n = calcFactors n n

calcFactors :: (Integral a) => a -> a -> [a]
calcFactors n 1 = [1]
calcFactors n m = if m <= 0
                  then []
                  else if n `mod` m == 0
                       then m : calcFactors n (m-1)
                       else calcFactors n (m-1) 
