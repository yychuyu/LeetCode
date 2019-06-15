/*
//Runtime: 4 ms
//Memory Usage: 47.7 MB
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int [] base = new int [nums.length+1];
        for (int num : nums) {
            base[num] = 1;
        }
        
        ArrayList<Integer> result = new ArrayList<Integer>();
        for (int i=1; i<base.length; i++) {
            if (base[i] == 0) result.add(i);
        }
        // System.out.println()
        return result;
    }
}
*/

/*
//Runtime: 23 ms
//Memory Usage: 48.1 MB

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        Arrays.sort(nums);  // 排序
        int cur = 1;
        ArrayList<Integer> result = new ArrayList<>();  // 保存未出现的数
        for (int i=0; i<nums.length; i++) {
            if (nums[i] == cur) {
                cur += 1;
            } else if (nums[i] > cur) {
                while (nums[i] > cur) {
                    result.add(cur);
                    cur += 1;
                }
                cur += 1;
            }
        }
        while (nums.length >= cur) {
            result.add(cur);
            cur += 1;
        }
        // System.out.println(Arrays.toString(nums));
        return result;
    }
}
*/

//Runtime: 6 ms
//Memory Usage: 47.6 MB
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int i=0; i<nums.length; i++) {  // 出现过的数对应的位置都设置为负值
            int idx = Math.abs(nums[i])-1;
            nums[idx] = -Math.abs(nums[idx]);
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int i=0; i<nums.length; i++) {  // 检查仍然为正数的位置作为结果输出
            if (nums[i] > 0) {
                result.add(i+1);
            }
        }
        return result;
    }
}
