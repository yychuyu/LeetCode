/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
// 战胜88.26%
var addStrings = function(num1, num2) {
    let size1 = num1.length
    let size2 = num2.length
    let flag = 0
    let result = ''
    while ( size1 > 0 && size2 > 0) {
        let s1 = parseInt(num1[size1 - 1])
        let s2 = parseInt(num2[size2 - 1])
        let jz = s1 + s2 + flag
        result = jz % 10 + result
        flag = jz >= 10 ? 1 : 0
        size1 --
        size2 --
    }
    while (size1 > 0) {
        let s1 = parseInt(num1[size1 - 1])
        let jz = s1 + flag
        result = jz % 10 + result
        flag = jz >= 10 ? 1 : 0
        size1 --
    }
    while (size2 > 0) {
        let s2 = parseInt(num2[size2 - 1])
        let jz = s2 + flag
        result = jz % 10 + result
        flag = jz >= 10 ? 1 : 0
        size2 --
    }
    if (flag) {
        result = 1 + result
    }
    return result
};

console.log(addStrings('1', '999999999'))
console.log(addStrings('5165', '54865'))
