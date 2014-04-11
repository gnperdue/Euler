#!/usr/bin/env python


class PythagTriple:
    """Compute whether a given triple is pythagorean. Supplyt the sum."""
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
        self.sum = a + b + c
        self.pt = False
        if (a * a + b * b) == (c * c):
            self.pt = True

    def isPythagorean(self):
        return self.pt

    def sum(self):
        return self.sum
