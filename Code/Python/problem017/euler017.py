#!/usr/bin/env python

one_to_nine = {0: "", 1: "one", 2: "two", 3: "three", 4: "four", 5: "five",
               6: "six", 7: "seven", 8: "eight", 9: "nine"}

teens = {10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen",
         14: "fourteen", 15: "fifteen", 16: "sixteen", 17: "seventeen",
         18: "eighteen", 19: "nineteen"}

decades = {20: "twenty", 30: "thirty", 40: "forty", 50: "fifty", 60: "sixty",
           70: "seventy", 80: "eighty", 90: "ninety"}


def number_to_word(num):
    if num > 0 and num < 10:
        return one_to_nine[num]
    elif num >= 10 and num < 20:
        return teens[num]
    elif num >= 20 and num < 100:
        rem = num % 10
        num = num - rem
        return decades[num] + one_to_nine[rem]
    elif num >= 100 and num < 1000:
        simple = num % 100
        century = int((num - simple) / 100)
        if simple == 0:
            ender = ""
        else:
            ender = "and" + number_to_word(simple)
        return one_to_nine[century] + "hundred" + ender
    if num == 1000:
        return "onethousand"
    return ""


def euler():
    lettered = ""
    for i in range(1, 1001):
        lettered += number_to_word(i)
    print len(lettered)


if __name__ == '__main__':
    euler()
