/** 
 * Note: The returned array must be malloced, assume caller calls free(). 
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {    
	int i = 0, j = 0;    
	int *twoSum_array = NULL;
        
	twoSum_array = (int *)malloc(sizeof(int)*2);    
	if (!twoSum_array) {        
		*returnSize = 0;        
		return NULL;    
	}    
	memset(twoSum_array, 0, 2*sizeof(int));
    
	for (i = 0; i < numsSize; i ++) {        
		for (j = i + 1; j < numsSize; j ++) {            
			if (target == nums[i] + nums[j]) {                
				twoSum_array[0] = i;                
				twoSum_array[1] = j;            
			}        
		}    
	}
        
	*returnSize = 2;    
	return twoSum_array;
}
