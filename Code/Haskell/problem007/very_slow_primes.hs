import Data.Ratio

pprime :: (Eq a, Integral a) => a -> [a]
pprime 1 = [2] 
pprime 2 = 3 : pprime 1
pprime n = pprimer
  where pprimer = if ( False == (or $ map (==1) $ map denominator $ fmap (n%) $ pprime (n-1)) )
                  then n : pprime (n-1)
                  else pprime (n-1)

