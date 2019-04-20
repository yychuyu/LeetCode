class Solution {
    public int[][] transpose(int[][] A) {
        //产生确定新数组的两个数字
		int[][] B = new int[A[0].length][A.length];
        //重新布阵
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
}