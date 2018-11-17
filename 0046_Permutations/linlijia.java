class Solution {
    public List<List<Integer>> permute(int[] nums) {
	
		List<List<Integer>> res = new ArrayList<>();
		backtrack(res, new ArrayList<Integer>(), nums);
		return res;
    }
	
	private void backtrack(List<List<Integer>> res, List<Integer> tmpList, int[] nums) {
	
		if (tmpList.size() == nums.length){
			res.add(new ArrayList(tmpList));
		} else {
			for (int i = 0; i < nums.length; i++) {
				if (tmpList.contains(nums[i])) 
                    continue;
                tmpList.add(nums[i]);
                backtrack(res, tmpList, nums);
                tmpList.remove(tmpList.size() - 1);
			}
		}
	
	}
}