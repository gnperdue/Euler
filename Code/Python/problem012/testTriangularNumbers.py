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


if __name__ == '__main__':
    tests()
