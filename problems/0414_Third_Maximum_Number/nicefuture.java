/*
// 思路一
class Solution {
    public int thirdMax(int[] nums) {
        Arrays.sort(nums);  // 完全排好序
        
        Set<Integer> last = new HashSet<Integer>();  // 查找第三大的数，重复的不算
        int result = nums[nums.length-1];
        
        for (int i=nums.length-1; i>=0 && last.size()<3; i--) {
            if (last.add(nums[i])) {
                result = nums[i];
            }
        }
        
        if (last.size() == 3) return result;
        else return nums[nums.length-1];
    }
}

*/

/*
// 思路二
class Solution {
    public int thirdMax(int[] nums) {
        int ceiling = 3;
        for (int i=0; i<ceiling && i<nums.length; i++) {
            int maxi = i;
            for (int j=i+1; j<nums.length; j++) {
                if (nums[j] > nums[maxi]) maxi = j;
            }
            
            if (i>0 && nums[maxi] == nums[i-1]) ceiling += 1;  //出现相同的数据，遍历的次数需要增加
                
            int t = nums[i];
            nums[i] = nums[maxi];
            nums[maxi] = t;
            
        }
        
        //System.out.println(Arrays.toString(nums));
        
        Set<Integer> front = new HashSet<>();
        int result = 0;
        for (int j=0; front.size()<3 && j<nums.length; j++) {
            
            if (front.add(nums[j])) result = nums[j];
        }
        if (front.size() == 3) return result;
        else return nums[0];
    }
}

*/

class Solution {
    public int thirdMax(int[] nums) {
        int [] result = new int[3];
        int free = 3;  // result 空闲的位置数量
        
        result[0] = result[1] = result[2] = 0;
        for (int i=0; i<nums.length; i++) {
            // System.out.println(Arrays.toString(result));
            if (free == 3) {  // 临时填充当前元素作为最大值
                result[2] = nums[i];
                free -= 1;
            }
            else if (nums[i] > result[2]) {  // 更新最大值
                result[0] = result[1];
                result[1] = result[2];
                result[2] = nums[i];
                free -= 1;
            }
            else if (nums[i] < result[2]) {  // 第二大的数候选
                if (free == 2) {  // 临时填充当前元素作为第二大的数
                    result[1] = nums[i];
                    free -= 1;
                }
                else if (nums[i] > result[1]) {  // 更新第二大的数
                    result[0] = result[1];
                    result[1] = nums[i];
                }
                else if (nums[i] < result[1]) {  // 第三大的数候选
                    // System.out.println(nums[i]);
                    if (free == 1) {  // 临时填充当前元素作为第三大的数
                        result[0] = nums[i];
                        free -= 1;
                    }
                    else if (nums[i] > result[0])  // 更新第三大的数
                        result[0] = nums[i];
                }
            }
        }
        if (free > 0) return result[2];  // 仍有空闲的位置，说明不存在第三大的数
        else return result[0];
    }
}
