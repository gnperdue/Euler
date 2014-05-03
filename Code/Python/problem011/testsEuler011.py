#!/usr/bin/env python

import euler011


def tests():
    data = euler011.get_the_data()
    euler011.get_sw_to_ne(data)
    euler011.get_ne_to_sw(data)


if __name__ == '__main__':
    tests()
