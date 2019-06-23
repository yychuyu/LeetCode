/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let mergeNums = {}
    nums.forEach(num => {
        if (!mergeNums[num]) {
            mergeNums[num] = 1
        } else {
            mergeNums[num] += 1
        }
    })
    let result = nums[0]
    for(let key in mergeNums) {
        if (mergeNums[result] < mergeNums[key]) {
            result = key
        }
    }
    return result
}

console.log(majorityElement([3, 2, 3]))
console.log(majorityElement([2,2,1,1,1,2,2]))
