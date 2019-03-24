class Solution {
    public void setZeroes(int[][] matrix) {
        int row = matrix.length;
        int column = matrix[0].length;
        int[] r = new int[row];
        int[] c = new int[column];
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(matrix[i][j] == 0){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        for(int i=0;i<row;i++){
            if(r[i] ==1){
                for(int j=0;j<column;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<column;j++){
            if(c[j] == 1){
                for(int i=0;i<row;i++){
                    matrix[i][j] =0;
                }
            }
        }
    }
}