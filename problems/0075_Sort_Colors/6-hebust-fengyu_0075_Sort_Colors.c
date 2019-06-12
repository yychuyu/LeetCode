/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 */


void sort_count(int arr[], int numsSize){
    int arr_count[3] = {0};
    int *tmp = (int *)malloc(sizeof(int) * numsSize);
    memcpy(tmp, arr, sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; ++i){
        arr_count[arr[i]] += 1;
    }
    for(int i = 1; i < 3; ++i){
        arr_count[i] += arr_count[i - 1];
    }
    for(int i = numsSize; i; --i){
        arr[arr_count[tmp[i - 1]] - 1] = tmp[i - 1];
        arr_count[tmp[i - 1]] -= 1;
    }
    free(tmp);
}


void sortColors(int* nums, int numsSize){
    sort_count(nums, numsSize);
}



