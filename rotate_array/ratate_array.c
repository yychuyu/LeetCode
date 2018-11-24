void rotate(int* nums, int numsSize, int k) {
   int tmp = 0;
    while(k != 0)
     {
        tmp  = nums[numsSize-1]; 
        for(int i=numsSize; i>0; i--)
        {
          nums[i] = nums[i-1];
        } 
        nums[0] = tmp;
        k--;
     }
  
    nums[numsSize] = '\0';
    
}
