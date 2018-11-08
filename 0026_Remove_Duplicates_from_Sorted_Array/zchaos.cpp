/**
* LeetCode The 26th problem :remove-duplicates-from-sorted-array
* Auth:zchaos
* Date:2018-10-08
*faster than 91.26% in¡Ïø€ 
**/ 
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize<=0){
            return 0;
        }
        int index = 1;
        for(int i=1;i<numsSize;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            nums[index] = nums[i];
            index++;
        }
        return index;
}
