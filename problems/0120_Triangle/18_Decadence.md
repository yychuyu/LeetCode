## 题目

```text
Leetcode 120
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
```

##解题思路
```text
给出一个三角形状的整数list，从第一行向下移动，每次只能向下一行相邻的数移动，要求求出从第一行到最后一行所经过的数字的和最小的方法。
这是一道动态规划的题目，我首先想到的是用一个二维数组存储从第一行到某行某个数的经过数的最小值，这是空间为o(n*n),
对其中第i行（i>1）的第j个数（0<j<row-1）有res[i][j]=Math.min(res[i-1][j-1],res[i-1][j])+list.get(j)，
即从上一行能到达该点的两个点中选择小的那个点，然后到达该点加上当前点的值即可。对于每行的第一个点和最后一个点，
只有一种方法能到达该点，所以直接加上当前点的值即可。最后遍历每个数即可得到最终结果。
```


## 代码

```java
public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int row=triangle.size();    //行数
        if(row==0) return 0;
         
        int[][] res=new int[row][row];  //记录从第一行到每个点的最小值
        int minSum=Integer.MAX_VALUE;       //记录最小的sum
        List<Integer> list0=triangle.get(0);  //第1行只有一个数，
        if(list0.size()==0)
            return 0;
        if(row==1) 
            return list0.get(0); 
        res[0][0]=list0.get(0);
        for(int i=1;i<row;i++){
            List<Integer> list=triangle.get(i);
            for(int j=0;j<list.size();j++){
                if(j==0){
                    res[i][j]=res[i-1][j]+list.get(j);
                }else if(j==list.size()-1){
                    res[i][j]=res[i-1][j-1]+list.get(j);
                }else{
                    res[i][j]=Math.min(res[i-1][j-1],res[i-1][j])+list.get(j);
                }
                if(i==row-1){
                    if(minSum>res[i][j])
                        minSum=res[i][j];
                }
            }
        }
        return minSum;
    }
}
```