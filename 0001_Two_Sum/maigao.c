/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    static int newarry[2]={0};
    
	//1.暴力解法--冒泡排序(已完成) 2.哈希表法(未完成)
    for (int i = 0; i < numsSize; i++)
       for (int j = i+1; j < numsSize; j++) 
       {
           if(!( target - nums[i] - nums[j]))
           {
               newarry[0] = i;
               newarry[1] = j;
               return newarry;
           } 
       }   
    return 0;
}              //by麦糕
