class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        HashSet<List<Integer>> set = new HashSet<>();
        List<List<Integer>> result = new ArrayList<>();
        if (nums.length == 4) {
            if (nums[0] + nums[1] + nums[2] + nums[3] == target) {
                List<Integer> temp = new ArrayList<>();
                temp.add(nums[0]);
                temp.add(nums[1]);
                temp.add(nums[2]);
                temp.add(nums[3]);
                result.add(temp);
            }
            return result;
        }
        Arrays.sort(nums);
        for(int start = 0; start < nums.length - 3; start++) {
            for(int end = nums.length - 1; end - start > 2; end--){
                int left = start + 1;
                int right = end - 1;
                while (left < right){
                    int sum = nums[start] + nums[left] + nums[right] + nums[end];
                    if (sum == target) {
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[start]);
                        temp.add(nums[left]);
                        temp.add(nums[right]);
                        temp.add(nums[end]);
                        set.add(temp);
                        left++;
                    }
                    else if (sum < target) {
                        left ++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        for(List<Integer> t: set)
            result.add(t);
        return result;
    }
}