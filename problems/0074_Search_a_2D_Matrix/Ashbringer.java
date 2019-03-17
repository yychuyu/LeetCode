/**
 * @Author 宋宗垚
 * @Date 2019/3/1 15:15
 * @Description 74——搜索二维矩阵,由于数组展开就是有序数列，本题中使用的是二分查找法
 */
public class Ashbringer {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length==0){
            return false;
        }
        int x = matrix.length;
        int y = matrix[0].length;
        int left = 0;
        int right = x*y-1;
        int mid ;
        boolean result = false;
        while (left<=right){
            mid = (left+right)/2;
            y = mid%matrix[0].length;
            x = (mid-y)/matrix[0].length;
            if(target==matrix[x][y]){
                result = true;
                break;
            }
            else if(target<matrix[x][y]){
                right = mid-1;
            }else if (target>matrix[x][y]){
                left = mid+1;
            }
        }
        return result;
    }


}
