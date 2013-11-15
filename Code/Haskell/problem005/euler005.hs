
euler = testdivs 20 testList

testdivs n xs
 | isEvenDivis n xs = n
 | otherwise = testdivs (n+1) xs

testList = [7,11,12,13,14,15,16,17,18,19,20]

isEvenDivis _ [] = True
isEvenDivis n (x:xs) 
 | n `rem` x == 0 = isEvenDivis n xs
 | otherwise = False

main = print euler
