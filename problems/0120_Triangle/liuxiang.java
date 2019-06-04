/**
解题思路：从上往下遍历，如果是第一列(j=0)的元素，那它的上一个元素只能是上一行的第一列的元素，如果是每一行的最后一个元素，那上一个元素应该是上一行的最后一个元素，如果这两种都不是，假设此时是第j行，那上一个元素是上一行的第j列或者第j-1列，取两者更小值，建立一个数组，用来存储从上往下走时到了每一步的步数和，故数组中元素的值等于给出的列表在该位置的值加上上一个元素的值，那最后一行就存储了从上到下可能的步数和，将最后一行求最小值就是要返回的值。
*/
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
         int n=triangle.size();
        int[][] a=new int[n][n];
        a[0][0]=triangle.get(0).get(0);
      //  System.out.println(triangle.get(2).size());
        for(int i=1;i<n;i++) {
        	for(int j=0;j<triangle.get(i).size();j++) {
        		if(j==0) {
        			a[i][j]=a[i-1][j]+triangle.get(i).get(j);
        		}else if(j==triangle.get(i).size()-1) {
        			a[i][j]=a[i-1][j-1]+triangle.get(i).get(j);
        		}else {
        			a[i][j]=Math.min(a[i-1][j], a[i-1][j-1])+triangle.get(i).get(j);
        			}
        	}
        }
       
        int min=a[n-1][0];
      //  System.out.println(min);
        for(int i=1;i<a[n-1].length;i++) {
        	min=Math.min(min, a[n-1][i]);
        }
		
		return min;
    }
}
