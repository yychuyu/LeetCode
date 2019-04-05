class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums.length == 0){
            return result;
        }
        DFS(nums,0,result);
        return result;
    }

    public void DFS(int[] nums, int k, List<List<Integer>> result){
        if(k == nums.length){
            List<Integer> list = new ArrayList<>();
            for (int num : nums) {
                list.add(num);
            }
            result.add(list);
            return;
        }
        for(int i=k; i<nums.length; i++){
            swap(nums,i,k);
            DFS(nums,k+1,result);
            swap(nums,i,k);
        }

    }
    public void swap(int[] nums, int i, int k){
        int tem = nums[i];
        nums[i] = nums[k];
        nums[k] = tem;
        return;
    }
}