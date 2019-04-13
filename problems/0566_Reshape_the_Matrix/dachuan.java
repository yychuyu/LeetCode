class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        //首先要看下 nums 有多少元素 total
        int total = nums.length * nums[0].length;
        //比较 r * c 和 total
        int productNum = r * c;
        boolean isReshape = total == productNum;
        if(!isReshape){
            //如果不相等刚返回原数组
            return nums;
        }else{}
            //如果相等，将产生新的数组
            int[][] newNums = new int[r][c];
            //将原数组行遍历
            int[] rowTraverse = new int[total];
            int index = 0;
            for (int i = 0; i < nums.length; i++) {
                for (int j = 0; j < nums[0].length; j++) {
                    rowTraverse[index] = nums[i][j];
                    index++;
                }
            }
            //将行遍历后的 nums 填入 newNums 中
            index = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    newNums[i][j] = rowTraverse[index];
                    index++;
                }
            }
            //返回 newNums
            return newNums;
    }
}