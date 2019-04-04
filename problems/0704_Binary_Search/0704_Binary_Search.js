/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    const find = (left, right) => {
        if(left === right && nums[left] !== target) {
            return -1;
        }
        const mid = ~~((left + right) / 2)
        if(nums[mid] > target) {
            return find(left, mid);
        } else if (nums[mid] === target) {
            return mid;
        } else {
            return find(mid + 1, right)
        }
    }

    return find(0, nums.length - 1);
};