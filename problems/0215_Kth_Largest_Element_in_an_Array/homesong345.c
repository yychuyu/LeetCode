/*************************************************************************
	> File Name: homesong345.c
	> Author:    SKLance
	> Mail:      zhangzewu345@126.com
	> Created Time: 2018-12-14 02:08:39
 ************************************************************************/


/*************************************************************************
 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

 示例 1:

 输入: [3,2,1,5,6,4] 和 k = 2
 输出: 5
 示例 2:

 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 输出: 4
 说明:

 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

 ************************************************************************/
void quickSort(int* a, int low, int high){
    if(low > = high) return ;
    int Left = low;
    int Right = high;
    int tmp = a[Left];
    while(Left != Right){
        while(Left < Right && a[Right] >= tmp )
            --right;
        a[Left] = a[Right];
        while(Left < Right &&  a[Left] <= tmp )
            ++Left;
        a[Right] = a[Left];
    }
    a[Left] = tmp;
    quickSort(a,low,Left-1);
    quickSort(a,Left+1,Right);
}

int findKthLargest(int * nums, int numsSize, int k){
    quickSort(nums,0,numsSize-1);
    return nums[numsSize-k];
}
