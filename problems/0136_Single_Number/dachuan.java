class Solution {
	//方法一
    public int singleNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num: nums){
            if(set.contains(num)){
                set.remove(num);
            }else{
                set.add(num);
            }
        }
        if (set.size() == 1) {
            Iterator<Integer> iterator = set.iterator();
            return iterator.next();
        }
        return -1;
    }
	//方法二
	public int singleNumber2(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int sum1 = 0, sum2 = 0;
        for (int num: nums){
            set.add(num);
            sum1 += num;
        }
        
        for (int num : set) {
            sum2 += num;
        }
        return sum2 * 2 - sum1;
    }
}