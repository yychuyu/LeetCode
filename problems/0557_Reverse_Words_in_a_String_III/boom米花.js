/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let arr = s.split(' ')
    let result = arr.map(item => {
    	return item.split('').reverse().join('')
    })
    return result.join(' ')
};