import Data.List

main = print $ (sort perms) !! 999999

perms :: [Integer]
perms = [ a*1000000000 + 
          b*100000000 + 
          c*10000000 + 
          d*1000000 + 
          e*100000 + 
          f*10000 + 
          g*1000 + 
          h*100 + 
          i*10 + 
          j | 
        a <- [0..9],
        b <- [0..9],
        c <- [0..9],
        d <- [0..9],
        e <- [0..9],
        f <- [0..9],
        g <- [0..9],
        h <- [0..9],
        i <- [0..9],
        j <- [0..9],
        10 == (length . nub) [a,b,c,d,e,f,g,h,i,j] ]

