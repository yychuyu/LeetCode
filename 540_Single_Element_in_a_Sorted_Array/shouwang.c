/*================================================================
*   Copyright (C) 2018 . All rights reserved.
*   
*   文件名称：540_Single_Element_in_a_Sorted_Array.c
*   创 建 者：hyb
*   创建日期：2018年09月06日
*   描    述：
*
================================================================*/

int singleNonDuplicate(int* nums, int numsSize) {
    if(NULL == nums || 0 == numsSize)
        return 0;
    if(1 == numsSize)
        return nums[0];
    int loop = 0;
    int num = 0;
    for(loop = 0; loop < numsSize;loop++)
        num^=nums[loop];
    return num;
}
