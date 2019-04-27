int findMaxConsecutiveOnes(int* nums, int numsSize) 
{
    int record_1 = 0;//记录1出现的次数
    int last_record_1 = 0;//记录统计过程中上一次1出现的次数
    int i = 0;
    
    for (i=0; i<numsSize; i++)
    {
        if (nums[i] != 0)
        {
            record_1++;
        }
        else if (record_1 >= last_record_1)
        {
            last_record_1 = record_1;
            record_1 = 0;
        }
        else if (record_1 < last_record_1)
        {
            record_1 = 0;
        }
    }
    return (record_1 > last_record_1?record_1:last_record_1);
}