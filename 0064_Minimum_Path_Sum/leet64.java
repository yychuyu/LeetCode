public class leet64 {

    public static void main(String[] args) {
        int [][]grid = {{1,3,1},{1,5,1},{4,2,1}};
        System.out.println(leet64.minPathSum(grid));
    }

    public static int minPathSum(int[][] grid) {
        int length = grid.length; //m行
        if(length==0){
            return 0;
        }
        int n = grid[0].length; //n列

        //构造矩阵
        int [][]mps = new int[length][n];
        mps[0][0] = grid[0][0];
        //对第一行处理
        for(int i=1;i<length;i++){
            mps[i][0] = grid[i][0]+mps[i-1][0];
        }
        //对第一列处理
        for(int j=1;j<n;j++){
            mps[0][j] = grid[0][j]+mps[0][j-1];
        }

        //其他行列处理,从第二行开始
        for(int i=1;i<length;i++){
            for(int j=1;j<grid[i].length;j++){
                mps[i][j] = Math.min( mps[i][j-1],mps[i-1][j] )+grid[i][j];
            }
        }

        return mps[length-1][n-1];
    }

}
