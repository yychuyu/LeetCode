bool increasingTriplet(int* nums, int numsSize) {
    if(numsSize < 3)
        return false;//数组小于三个直接返回false
    int l = nums[0], max = 0x7fffffff;//最大正数
    for(int i = 1; i < numsSize; i++)
    {
        int a = nums[i];    //a开始为三个数中间的那个
        if(a <= l) 
            l = a;
        else if(a < max)
            max = a;
        else if(a > max)    //a大于前面两个数
            return true;
    }   
    return false;
}

