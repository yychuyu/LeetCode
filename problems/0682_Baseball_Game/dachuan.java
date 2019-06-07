class Solution {
    public int calPoints(String[] ops) {
        int i = 0;
        int[] nums = new int[ops.length];
        for (String str : ops) {
            switch (str) {
                case "+":
                    nums[i] = nums[i - 1] + nums[i - 2];
                    i++;
                    break;
                case "D":
                    nums[i] = nums[i - 1] * 2;
                    i++;
                    break;
                case "C":
                    nums[i - 1] = 0;
                    i--;
                    break;
                default:
                    nums[i] = Integer.parseInt(str);
                    i++;
                    break;
            }
        }
        int result = 0;
        for (int num: nums){
            result+=num;
        }
        return result;
    }
}