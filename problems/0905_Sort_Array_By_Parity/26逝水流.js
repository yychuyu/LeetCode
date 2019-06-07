/**
 * @param {number[]} A
 * @return {number[]}
 */
// 方法一
var sortArrayByParity = function(A) {
    let result = []
    for (let i = 0; i < A.length; i++) {
        if (A[i] % 2) {
            result.push(A[i])
        } else {
            result.unshift(A[i])
        }
    }
    return result
}

// 方法二
var sortArrayByParity = function(A) {
    let start = 0
    let end = A.length - 1
    while (start < end) {
        while (A[start] % 2 === 0) {
            start ++
        }
        while (A[end] % 2) {
            end --
        }
        if (start < end) {
            let midRst = A[start]
            A[start] = A[end]
            A[end] = midRst
            start ++
            end --
        }
    }
    return A
}

console.log(sortArrayByParity([3, 1, 2, 4]))
console.log(sortArrayByParity([0, 2]))
