 /**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for( let i = 0,l = nums.length; i < l; i++){
       for(let j = 0; j< l; j ++){
         if(target - nums[i] === nums[j]){
             return [i,j];
         }
       }    
    }
	return [];
};
    //测试代码 
    let nums = [2, 7, 11, 15], target = 9;
    console.log(twoSum(nums, target));
