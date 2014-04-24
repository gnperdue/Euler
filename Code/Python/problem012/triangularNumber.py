import numpy as np


class TriangularNumber:
    def __init__(self, initial_value, max_factors=1000):
        self._value = initial_value
        self._triangular_num = 0
        self._max_factors = max_factors
        self._factors = np.zeros(max_factors)
        self._computed_factors = False
        self.calc_triangle()

    def calc_triangle(self):
        temp_value = self._value
        self._triangular_num = 0
        while temp_value != 0:
            self._triangular_num += temp_value
            temp_value -= 1

    def set(self, value):
        self._value = value
        self._computed_factors = False
        self.calc_triangle()

    def get(self):
        return self._triangular_num

    def _compute_factors(self):
        if not self._computed_factors:
            self._factors = np.zeros(self._max_factors)
            self._factors[0] = 1
            index = 1
            factor = 2

            while (factor <= self._triangular_num) and \
                    (index < self._max_factors):
                if self._triangular_num % factor == 0:
                    self._factors[index] = factor
                    index += 1

                factor += 1

            if self._triangular_num > factor:
                print "Warning: Insufficient maximum number of factors"

    def factors(self):
        self._compute_factors()
        factors = self._factors[self._factors > 0]
        return factors

    def nfactors(self):
        self._compute_factors()
        factors = self._factors[self._factors > 0]
        return factors.size
