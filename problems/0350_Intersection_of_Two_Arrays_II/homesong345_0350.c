/*************************************************************************
	> File Name: homesong345.c
	> Author:    SKLance
	> Mail:      zhangzewu345@1126.com 
	> Created Time: 2018-11-29 04:10:55
 ************************************************************************/

/*************************************************************************
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 ************************************************************************/
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*****************快速排序********************/
void quick_sort(int *s, int left, int right){

    if(left < right){
        int i = left;
        int j = right;
        int x = s[left];
        while(i < j){
            while(i < j && s[j] >= x)
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i] <= x)
                i++;
            if(i < j)
                s[j--] = s[i];
        }

        s[i] = x;
        quick_sort(s,left,i-1);
        quick_sort(s,i+1,right);
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *inter ,k;
    int i = 0;
    int j = 0;
    int n = 0;
    int m = 0;

    if(nums1Size > nums2Size)   k = nums2Size;
    else                        k = nums1Size;
    inter = (int *)malloc(sizeof(int) * k );

    quick_sort(nums1,0,nums1Size-1);
    quick_sort(nums2,0,nums2Size-1);

    while(i != nums1Size && j != nums2Size){
        if(nums1[i] <= nums2[j]){
            if(nums1[i] == nums2[j]){
                inter[n++] = nums1[i];
                j++;
            }
            i++;
        }
        if(nums1[i] > nums2[j])
            j++;
    }
    *returnSize = n;
    return inter;
}
