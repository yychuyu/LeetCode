class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //先排序
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                break;
            }
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.length - 1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    result.add(Arrays.asList(new Integer[]{nums[i], nums[left], nums[right]}));
                    while(left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right-1]) {
                        right--;
                    }
                    right--;
                    left++;
                }else if(target > nums[left] + nums[right]) {
                    left++;
                }else {
                    right--;
                }
            }
        }
        return result;
    }
}