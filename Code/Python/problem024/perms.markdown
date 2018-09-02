
# built-ins

    In [1]: import itertools
    
    In [2]: itertools.permutations([1, 2, 3])
    Out[2]: <itertools.permutations at 0x103d52b30>
    
    In [3]: for p in itertools.permutations([1, 2, 3]):
       ...:     print p
       ...:
    (1, 2, 3)
    (1, 3, 2)
    (2, 1, 3)
    (2, 3, 1)
    (3, 1, 2)
    (3, 2, 1)
    
    In [4]: print list(itertools.permutations([1, 2, 3]))
    [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]

# algs

See http://stackoverflow.com/questions/104420/how-to-generate-all-permutations-of-a-list-in-python
