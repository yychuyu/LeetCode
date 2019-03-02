leetcode 
int* twoSum(int* nums, int numsSize, int target) 
{
 
    int i=0,j=0;
    
    while(nums[i]+nums[j] != target)
    {
        while(j < numsSize-1)
        {
            for(i++,i < numsSize-1; j++;);            
        }
    }
    
    printf("%d,%d", i, j);
    
    return 0;
}

int* twoSum(int* nums, int numsSize, int target)
{
   static int a[2]={0};//静态 整型 一维 数组 初始化
	for (int i = 0; i < numsSize - 1; i++)
	{
		for (int j = i+1; j < numsSize; j++)//题目中说，不能重复利用这个数组中的同样元素，即同一个元素不能连续调用，i从a[0]开始，那么j就不能取a[0]，此处从a[1]开始了
		{
			if (nums[i] + nums[j] == target)
			{
				a[0]=i;
                a[1]=j;
                
                return a;  //返回静态常量，在程序执行后再释放内存，否则内部变量执行完就释放，无法取得目标值
			}
		}
	}
	return 0;
}