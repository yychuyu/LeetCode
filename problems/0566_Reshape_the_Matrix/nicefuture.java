class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int row = nums.length, column = nums[0].length;
        if (r*c != row*column) return nums;
        
        int[][] reshaped = new int[r][c];
        int r_new = 0, c_new = 0;
        for (int i=0; i<row; i++) {
            for (int j=0; j<column; j++) {
                reshaped[r_new][c_new] = nums[i][j];
                if (c_new+1 == c) {
                    c_new = 0;
                    r_new += 1;
                } else {
                    c_new += 1;
                }
            }
        }
        
        return reshaped;
    }
}
