#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYSIZE(buf) sizeof(buf)/sizeof(buf[0])
int* fourSum(int* nums, int numsSize, int target, int* returnSize);
void display(int *p,int size);

int main(int argc, char *argv[])
{
	 int nums_m[ ] = {1,2,3,4,5,6,7,8,9,10,11,12,-3};
	int *p;
	int target_m = 18;
	int retsize_m = 0;
	
	p = fourSum(nums_m,ARRAYSIZE(nums_m),target_m,&retsize_m);
	//display(p,retsize_m);
	printf("[%d, %d, %d, %d],\n",*p++,*p++,*p++,*p++);
	
	return 0;
}


void display(int *p,int size)
{
	int i,j;
	printf("[");
	for(i = 0; i < size/16; i++)
	{
		for(j = 0 ; j < 4; j++)
		{
			printf("[%d, %d, %d, %d],\n",*p++,*p++,*p++,*p++);
		}
	}
	printf("]");
}

int* fourSum(int* nums, int numsSize, int target, int* returnSize) {
	int i,j,k,l;  
	int *retp ;//实际需要返回的指针
	int *ret = retp;

	for(i = 0; i < numsSize; i++)
		for(j = i + 1; j < numsSize; j++)
			for(k = j + 1; k < numsSize; k++)
				for(l = k + 1; l < numsSize; l++)
				{
					//找到对应的数据
					if((nums[i] + nums[j] + nums[k] + nums[l]) == target)
					{
							
							printf("nums[%d] = %d  nums[%d] = %d  nums[%d] = %d  nums[%d] = %d\n",i,nums[i],j,nums[j],k,nums[k],l,nums[l]);
						    ret = (int *)malloc(sizeof(int) * 4);	
							memset(ret,0,4);
							*ret++ = nums[i];
							*ret++ = nums[j];
							*ret++ = nums[k];
							*ret++ = nums[l];
							(*returnSize) +=(sizeof(int) * 4);
							printf("%d -- ",*returnSize);
					}
				}
	printf("\n");
	return retp;
}
