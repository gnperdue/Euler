
isPalindromic n = show n == reverse (show n)

euler4 = maximum [ x*y | x <- [900..999], y <- [x..999], isPalindromic (x*y) ]

main = print euler4
