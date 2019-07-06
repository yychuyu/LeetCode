/**
 * @param {number[]} digits
 * @return {number[]}
 */
// 战胜34.22%
var plusOne = function(digits) {
    if (!digits || digits.length === 0) {
        return [1]
    }
    let total = digits.length
    let flag = 0
    let midRst = digits[total - 1] + 1
    while (total > 0) {
        midRst = midRst + flag
        digits[total - 1] = midRst % 10
        flag = 1
        total --
        if (midRst < 10) {
            flag = 0
            break
        }
        midRst = digits[total - 1]
    }
    if (flag) {
        digits.unshift(1)
    }
    return digits
};

console.log(plusOne([1, 2, 3]))
console.log(plusOne([4, 3, 2, 1]))
console.log(plusOne([1, 5, 9, 9]))
console.log(plusOne([9, 9, 9, 9, 9]))
