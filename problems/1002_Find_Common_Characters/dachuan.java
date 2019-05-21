class Solution {
    public List<String> commonChars(String[] A) {
        //第1步：选一个基准字符串，转换为26个数字的数组
        int[] baseNums = new int[26];
        for(char ch: A[0].toCharArray()){
            baseNums[ch - 'a']++;
        }
        //第2步：通过和其他每个字符串比较，逐步得出以26个数字组成的数组式的答案
        for (int i = 1; i < A.length; i++) {
            int[] nums = new int[26];
            for(char ch : A[i].toCharArray()){
                nums[ch - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                baseNums[j] = Math.min(baseNums[j], nums[j]);
            }
        }
        //第3步：将数据转换为字符串集合
        List<String> result = new ArrayList<>();
        for (int i = 0; i < baseNums.length; i++) {
            if(baseNums[i] > 0){
                for (int j = 0; j < baseNums[i]; j++) {
                    result.add((char)(i + 'a') + "");
                }
            }
        }
        return result;
    }
}