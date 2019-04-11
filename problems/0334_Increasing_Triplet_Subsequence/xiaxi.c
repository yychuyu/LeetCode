bool increasingTriplet(int* nums, int numsSize) {
    int n,min,second_min;
    
    n = 0;
    min = 0x7fffffff;
    second_min = 0x7fffffff;
    
    if (numsSize < 3)
    {
        return false;
    }
    else
    {
        for (n=0; n<numsSize;n++)
        {
            if (nums[n] <= min)
                min = nums[n];
            else if (nums[n] < second_min)
                second_min = nums[n];
            else if (nums[n] > second_min)
                return true;
        }
        return false;
        
    }
    
}
