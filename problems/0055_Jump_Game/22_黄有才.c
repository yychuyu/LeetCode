
/*****************************************************************************************************************************
 * 思路一(第归版)：向前反推，要到达尾元素的必要条件是：尾之前的n个距离内（0之前）至少有一个值>=n；而在此值之前，也必定有一个距离n个位置的值>=n
 * 	   因此可用第归求解，若在>=0范围内找到该值，则返回true，结束条件尾>=0；否则返回false
 * TC: O(n)	SC: O(1) 
 * Runtime: 8 ms, faster than 79.11% of C online submissions
 * Memory Usage: 8.3 MB, less than 69.37% of C online submissions
 * **************************************************************************************************************************/
 
bool canJump(int* nums, int numsSize){
	if( 1 == numsSize )	return true;				//1.仅一个元素，首元素也是尾元素;2.第归到达首元素，直接返回true
	int pre = numsSize-2;						//尾元素是nums[numsSize-1]；pre是第n个元素，初始化为numSize-2，即前1个元素
	int value = 1;							//value是可以到达尾元素需满足的必要条件：前第n个元素的理想值为n，初始化为1
	while( pre >= 0 )						//若追查至0元素前依然未找到满足条件的第n个元素，则跳出循环，返回false
	{
		if( nums[pre] >= value++ )	return canJump(nums, pre+1);	//若前第value个元素值>=value，以nums[value]为待新尾元素继续第归
		--pre;							
	}
	return false;							
}  




/*****************************************************************************************************************************
 * 思路一(迭代版)：方法同上
 * TC: O(n)	SC: O(1)
 * Runtime: 8 ms, faster than 79.11% of C online submissions
 * Memory Usage: 7.9 MB, less than 94.29% of C online submissions 
 * **************************************************************************************************************************/
 
bool canJump(int* nums, int numsSize){
	if( 1 == numsSize )	return true;
	int pre = numsSize - 2;
	int value = 1;
	while( pre >= 0 )
	{
		if( nums[pre] >= value++ )	
		{	
			if( 0 == pre )	return true;				//当向前追查至nums[0]且满足条件时，结果为true
			value = 1;
		}
		--pre;			
	}
	return false;
}  


//类似思路，参考Discussion中更精简的写法	
//Reference: @lucastan <https://leetcode.com/problems/jump-game/discuss/20900/Simplest-O(N)-solution-with-constant-space>

bool canJump(int* nums, int numsSize){
	int last = numsSize - 1;						//last为待检查能否到达的最后变量
	for( int pre = numsSize-2; pre >= 0; pre-- )
	{
		if( pre+nums[pre] >= last )					//若前某节点能够到达last，则更新last为该节点，再重新检查当前last
			last = pre;
	}				
	return (last == 0);							//若last正好为0，表示可以从0jump至尾，则返回ture；否则false
}




/*****************************************************************************************************************************
 * 思路二：从首元素开始，计算每个下标元素可以到达的最远下标，以max记录最远值，一旦max>=尾元素下标，表示可以到达尾部；
 * 	  （有点类似波的传递，只要最远波能够达到标点(即尾元素)，就返回true）
 * TC: O(n)	SC: O(1)
 * Runtime: 8 ms, faster than 78.48% of C online submissions
 * Memory Usage: 8.3 MB, less than 62.83% of C online submissions
 * **************************************************************************************************************************/

bool canJump(int* nums, int numsSize){
        if( 1 == numsSize )     return true; 
        if( 0 == nums[0] )      return false;
        int max = nums[0];
        for( int i = 0; i < numsSize-1; i++ )
        {
                if( max == i && 0 == nums[i] )					//能够到达的最远点值为0，表示无法继续前进
                        return false;
                int distance = nums[i] + i;					//当前点能到达的最远距离
                max = (max < distance) ? distance:max;				//更新max
                if( max >= numsSize-1 )     
                        return true;
        }
        return false;
}


//参考discussion中与上类似的解法
//Reference: @alexander7 <https://leetcode.com/problems/jump-game/discuss/20917/Linear-and-simple-solution-in-C%2B%2B>

bool canJump(int* nums, int numsSize){
	int i = 0;								//i为当前检测的下标
	for( int reach = 0; i < numsSize && i <= reach; i++ )			//reach为能够到达的最远距离，若当前下标超过了能够到达最远距离表示无法到达当前及以后的下标，直接退出判断循环
	{
		if( i + nums[i] > reach )
			reach = i + nums[i];					//reach更新为能够到达的最远距离
	}
	return (i == numsSize);							//若结束循环后的检测下标等于尾元素，表示尾元素包括再可达到范围内
}




/*****************************************************************************************************************************
 * 失败思路：深搜，从首元素开始，以迭代+第归逐个尝试所有可能，当到达尾元素即结束。
 * 	     时间和内存消耗较大，但可以算出所以可能路线
 * TC: O(n2)	SC: O(n2)
 * 失败原因：若向回走可能会进入死循环，解决方案：每条路先都带一条链表记录前面经过的下标，保证此刻即将走的下一步不与之前重合
 * 	     但是需要消耗更大的额外内存，不考虑此方法
 * **************************************************************************************************************************/
