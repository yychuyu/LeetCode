//这一题和0055Jump Game的区别是，五只需要判断是否能到达，无需考虑步数；而这一题需要每走一步都保证最远（最优）以实现最少步数，
//因此需进行数组元素之间的比较，而检查元素本身的大小，0055中的部分解法在这里不适用

/**
 * 思路一：参考0055中思路三，贪心算法。
 * 	   每走一步都需要经过相同判断：1.先标记目前可到达的reach点，遍历检查此点之前可到达的最远距离，更新reach
 * 	   			       2.此时可以确定必须走出一步，因此计数器cnt++
 * 	   			       3.判断此时reach是否到达尾部，若到达，直接返回cnt；否则重新开始对reach进行判断
 * TC: O(n)	SC: O(1)
 * Runtime: 20 ms, faster than 31.08% of C online submissions
 * Memory Usage: 8.3 MB, less than 43.97% of C online submissions
 **/

int jump(int* nums, int numsSize){
	int reach = 0;
	int cnt = 0;
	for( int iterator = 0; iterator <= reach && reach < numsSize-1; )
	{
		int flag = reach;						//以flag标记此刻的reach，因为下面for循环中reach会被更新
		for( ; iterator <= flag; iterator++ )
		{
			if( iterator + nums[iterator] > reach )			//更新reach为目前可到达点（reach）能到达的下一个最远下标
				reach = iterator + nums[iterator];
		}
		++cnt;	
		if( reach >= numsSize - 1 )
			return cnt;
	}
	return cnt;								//这里return是处理数组长为1的情况
}


//这题和0055都做得十分不顺利，主要还是因为写代码之前没有完全理清楚思路，目前也仅想到一种方法。
//在Discussion中没有发现非常出色的方法
