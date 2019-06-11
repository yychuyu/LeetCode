/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function(nums, r, c) {
    let oriR = nums[0].length
    let oriC = nums.length
    if (r * c != oriR * oriC) {
        return nums
    }
    let result = [[]]
    let rstR = 0
    let eachC = 0
    for (let i = 0; i < oriC; i++) {
        for (let j = 0; j < oriR; j++) {
            if (eachC < c) {
                result[rstR].push(nums[i][j])
                eachC ++
            } else {
                rstR ++
                result[rstR] = []
                eachC = 0
                j --
            }
        }
    }
    return result
};

// console.log(matrixReshape([[1, 2], [3, 4]], 1, 4));
// console.log(matrixReshape([[1, 2], [3, 4]], 2, 4));
// console.log(matrixReshape([[1, 2], [3, 4]], 4, 1));
