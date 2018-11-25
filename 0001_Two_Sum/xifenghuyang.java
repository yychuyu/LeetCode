
/**
 * Created with IntelliJ IDEA.
 * Description:
 *  
 * @author: xifenghuyang
 * @Date: 2018-11-11
 * @Time: 15:03
 */

class Solution {
    public int[] twoSum(int[] nums, int target) {
        for(int i=0; i<nums.length-1; i++){
            for(int j=i+1; j< nums.length; j++){
                if((nums[i]+nums[j])==target)
                    return new int[] {i, j};
            }
        }
        throw null;
    }
}

