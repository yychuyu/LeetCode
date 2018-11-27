/*
  题目：
  给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

  说明:
  初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
  你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m&&n){
            if(nums1[m-1] > nums2[n-1]){
                nums1[m+n-1] = nums1[m-1];
                m--;
              
            }else{
                nums1[m+n-1] = nums2[n-1];
                n--;
            }
        }
        while(n){
            nums1[m+n-1] = nums2[n-1];
            n--;
        }
    }
};
