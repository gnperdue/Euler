
####Run the Profiler in IPython

    In [2]: import testTriangularNumbers

    In [3]: %prun -s cumulative testTriangularNumbers.tests()
             19 function calls in 0.000 seconds
    ...


####Use the Timer in IPython

    In [2]: %timeit testTriangularNumbers.tests()
    10000 loops, best of 3: 89.5 µs per loop


####Run the Profiler on the Command Line

    $ python -m cProfile testTriangularNumbers.py
         10466 function calls (10378 primitive calls) in 0.114 seconds
