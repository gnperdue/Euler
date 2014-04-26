#!/usr/bin/env python

import triangularNumber


def tests():
    tn = triangularNumber.TriangularNumber(7)
    tnum = tn.get()
    tfac = tn.factors()
    ntfac = tn.nfactors()

    assert tnum == 28
    assert ntfac == 6
    assert ntfac == tfac.size

    tn.set(6)
    tnum = tn.get()
    ntfac = tn.nfactors()

    assert tnum == 21
    assert ntfac == 4

    findval = 76576500
    triangn = 10
    tn.set(triangn)
    while tn.get() != findval:
        triangn += 1
        tn.set(triangn)
        if triangn % 1000 == 0:
            print triangn, tn.get()

    print "Found the triangular index at %d" % (triangn)

    triangn = 12375
    tn.set(triangn)
    print tn.get(), tn.nfactors()

if __name__ == '__main__':
    tests()
