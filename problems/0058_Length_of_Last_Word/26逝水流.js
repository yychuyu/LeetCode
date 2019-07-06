/**
 * @param {string} s
 * @return {number}
 */
// 战胜85.26%
var lengthOfLastWord = function(s) {
    if (!s || s.length === 0) {
        return 0
    }
    let result = 0
    let total = s.length
    while (total) {
        if (s[total - 1] != ' ') {
            result ++
        } else if (result !== 0) {
            break
        }
        total --
    }
    return result
}

console.log(lengthOfLastWord('Hello World'))
console.log(lengthOfLastWord('  '))
console.log(lengthOfLastWord('Hello World '))
