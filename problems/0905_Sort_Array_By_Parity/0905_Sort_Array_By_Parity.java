/**
 * Sort Array By Parity 905 
 * 微信号：VINO
 * 另外一种想法，如果题目考察数组中元素奇偶个数 考虑乘5mod10 最终将奇偶变换成 0 5 
 * 
*/



class Solution {
    public int[] sortArrayByParity(int[] A) {
        int left = 0 , right = A.length-1, temp = 0;
        while(left<=right)
        {
        	if(A[left]% 2 == 1 && A[right]% 2 == 0)//左偶右奇交换
        	{
        		temp = A[left];
        		A[left] = A[right];
        		A[right] = temp;
        		left++;
				right--;
        	}
        	else if(A[left]% 2 == 0)
        	{
        		left++;
        	}
        	else if(A[right]% 2 == 1)
        	{
        		right--;
        	}	
        }
        return A;
    }
}