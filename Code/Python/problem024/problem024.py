from __future__ import print_function
import itertools


def get_permutations(nums):
    """
    return the permutations, already in lexographic order
    """
    perms = itertools.permutations(nums)
    return perms


if __name__ == '__main__':
    l = list(get_permutations(list(range(10))))
    print(l[999999])
