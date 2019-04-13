//方法有三种，但第一次被 Leetcode 裁定超时，我自己在本地运行时可以成功，看来第一种方法太耗时了。
class Solution {
	//方法三（耗时最少）
	public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> map = new HashMap();
        for (int i = 0; i < numbers.length; i++) {
            int completion = target - numbers[i];
            if (map.containsKey(completion) && map.get(completion) != i) {
                return new int[]{map.get(completion) + 1, i + 1};
            }
            map.put(numbers[i], i);
        }
        return null;
    }
	//方法二
	public int[] twoSum2(int[] numbers, int target) {
        Map<Integer, Integer> map = new HashMap();
        for (int i = 0; i < numbers.length; i++) {
            map.put(numbers[i], i);
        }
        for (int i = 0; i < numbers.length; i++) {
            int completion = target - numbers[i];
            if(map.containsKey(completion) && map.get(completion) != i){
                return new int[]{i + 1, map.get(completion) + 1};
            }
        }
        return null;
    }
		//方法一（最耗时）
    public int[] twoSum1(int[] numbers, int target) {
        int[] result = new int[2];
        for (int i = 0; i < numbers.length - 1; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                if(numbers[i] + numbers[j] == target){
                    result[0] = i + 1;
                    result[1] = j + 1;
                    return result;
                }
            }
        }
        return null;
    }
}