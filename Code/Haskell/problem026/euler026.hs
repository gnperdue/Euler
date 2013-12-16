
euler26 = foldr step (0,0) [1..1000]
  where step x acc = let k = checkRepeatedFraction 1 x
                         in if k > fst acc
                              then (k,x)
                              else acc

checkRepeatedFraction :: Integral t => t -> t -> Int
checkRepeatedFraction m n = let (c,xs) = findRepeatedPairs m n
                                in if not c
                                     then 0
                                     else findDistanceBetweenEquals xs

findDistanceBetweenEquals :: Eq a => [a] -> Int
findDistanceBetweenEquals []  = 0
findDistanceBetweenEquals [x] = 1
findDistanceBetweenEquals all@(x:xs) = if anyEqual xs
                                         then findDistanceBetweenEquals xs
                                         else length xs

findRepeatedPairs :: Integral a => a -> a -> (Bool, [(a,a,a,a)])
findRepeatedPairs m n = buildRepeatedPairList m n 2

buildRepeatedPairList :: Integral a => a -> a -> Int -> (Bool, [(a,a,a,a)])
buildRepeatedPairList m n j = let (c,xs) = checkPairList m n j
                                  in if c 
                                       then (True,xs)
                                       else if length xs /= j
                                              then (False,xs)
                                              else buildRepeatedPairList m n (j+1)

checkPairList :: Integral a => a -> a -> Int -> (Bool, [(a,a,a,a)])
checkPairList m n j = let xs = take j $ makeDigitNPair m n 
                          in if length xs /= j
                               then (False, xs)
                               else (anyEqual xs, xs)

anyEqual :: Eq a => [a] -> Bool
anyEqual []     = False
anyEqual (x:xs) = elem x xs || anyEqual xs

makeDigitNPair :: Integral a => a -> a -> [(a,a,a,a)]
makeDigitNPair m n = makePair m n 0

makePair :: Integral a => a -> a -> a -> [(a,a,a,a)]
makePair 0 _ _ = [] 
makePair m n j 
 | m `div` n == 0 = makePair (10*m) n (j+1)
 | otherwise =  if j > 1 
                  then prependZeros m n (j-1) ++ [(m `div` n, n, j, m `rem` n)] ++ makePair (m `rem` n) n 0
                  else (m `div` n, n, j, m `rem` n) : makePair (m `rem` n) n 0

prependZeros :: Integral a => a -> a -> a -> [(a,a,a,a)]
prependZeros _ _ 0 = []
prependZeros m n j = (0,n,j,m) : prependZeros m n (j-1)

