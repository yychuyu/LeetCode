/**
Ã·Ωª’ﬂ£∫ª‘ 
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
    int i=0,j=0;
    int *ret=(int*)malloc(2*sizeof(int));
    for(i=0;i<numsSize;i++){
        //a=nums[i];
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                ret[0]=i;
                ret[1]=j;
                return ret;
            }
        }
        
    }
    return NULL;
}
