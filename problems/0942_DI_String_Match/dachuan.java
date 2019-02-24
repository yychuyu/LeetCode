class Solution {
    public int[] diStringMatch(String S) {
        char[] chars = S.toCharArray();
        int len = chars.length;
        int[] nums = new int[len + 1];
        int min = 0;
        int max = len;
        for(int i = 0; i< len; i++){
            if(chars[i] == 'I'){
                nums[i] = min;
                min++;
            }else if(chars[i] == 'D'){
                nums[i] = max;
                max--;
            }
        }
        nums[len] = min;
        return nums;
    }
}