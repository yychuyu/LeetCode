/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let tmpNums = {}
    nums.forEach((num, i) => {
        if (typeof(tmpNums[num]) == 'undefined') {
            tmpNums[num] = [i]
        } else { // 重复数字
            tmpNums[num].push(i)
        }
    })
    // console.log(`=== tmpNums: `, tmpNums)
    let result = []
    for (let key in tmpNums) {
        let otherNum = tmpNums[target - key]
        if (typeof(otherNum) !== 'undefined') {
            // console.log(`==== `, target, key, target - key - key <= 0, otherNum)
            if (target - key - key <= 0) {
                if (otherNum.length > 1) {
                    result = otherNum.slice(0, 2)
                    break
                }
            } else {
                result = tmpNums[key][0] < otherNum[0] ? [tmpNums[key][0], otherNum[0]] : [otherNum[0], tmpNums[key][0]]
                break
            }
        }
    }
    return result
}

// WA: 忘记考虑重复数字
// var twoSum = function(nums, target) {
//     let tmpNums = {}
//     nums.forEach((num, i) => {
//         if (num < target) {
//             tmpNums[num] = i
//         }
//     })
//     let result = []
//     for (let key in tmpNums) {
//         let otherNum = tmpNums[target - key]
//         if (typeof(otherNum) !== 'undefined') {
//             result = tmpNums[key] < otherNum ? [tmpNums[key], otherNum] : [otherNum, tmpNums[key]]
//             break
//         }
//     }
//     return result
// }

console.log(twoSum([2, 7, 11, 15], 9))
console.log(twoSum([3, 3], 6))
console.log(twoSum([0, 4, 3, 0], 0))
console.log(twoSum([-3, 4, 3, 90], 0))
