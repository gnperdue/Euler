
getPythag :: Double -> Double -> Double
getPythag a b = sqrt $ a*a + b*b

getPythags :: Double -> [(Double, Double, Double)]
getPythags n = [(x,y,z x y) | x <- [1.0..n], y <- [x..n], x + y + z x y == n ]
    where z = getPythag 

getTripleProducts :: Double -> [Double]
getTripleProducts n = map (\(a,b,c) -> a * b * c) list
    where list = getPythags n

main = print $ getTripleProducts 1000
