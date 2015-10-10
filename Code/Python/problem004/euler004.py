#!/usr/bin/env python3


def is_palindromic(num):
    if str(num) == str(num)[::-1]:
        return True
    return False


def euler004():
    max_palindrome = 0
    for n1 in range(900, 1000):
        for n2 in range(n1, 1000):
            n = n1 * n2
            if is_palindromic(n):
                if n > max_palindrome:
                    max_palindrome = n
    return max_palindrome


if __name__ == '__main__':
    answer = euler004()
    print(answer)
    # else we have been loaded as a module...
