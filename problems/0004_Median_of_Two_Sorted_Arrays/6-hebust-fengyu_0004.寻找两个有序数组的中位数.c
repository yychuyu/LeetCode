/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 */


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int flag = (nums1Size + nums2Size) % 2;
    int pos = (nums1Size + nums2Size) / 2;
    int size = nums1Size + nums2Size;
    int *array = (int *)malloc(sizeof(int) * size);
    while(nums1Size && nums2Size){
        array[--size] = nums1[nums1Size - 1] > nums2[nums2Size - 1] ? nums1[--nums1Size] : nums2[--nums2Size]; 
    }
    while (nums1Size)
    {
        array[--size] = nums1[--nums1Size];
    }
    while(nums2Size){
        array[--size] = nums2[--nums2Size];
    }
    if(flag){
        return array[pos];
    }
    else{
        return (array[pos] + array[pos - 1]) / 2.0;
    }
    
}



