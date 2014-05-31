function collatzLength(start) {
    if (start <= 0) return 0;
    var leng = 1;
    while (start > 1) {
        if (start % 2 === 0) {
            leng += 1;
            start = start / 2;
        } else {
            leng += 1;
            start = 3 * start + 1;
        }
    }
    return leng;
}

function max(current, next) {
    if (current > next) return current;
    return next;
}

var nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
var cols = nums.map(collatzLength);
print(cols);
var longest = cols.reduce(max);
print(longest);
