
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1 + len2;
        vector<int> nums(len);
        int num1 = 0, num2 = 0;
        for (int m = 0;m<len;m++) {
            if (num1 == len1) {
                nums[m] = nums2[num2];
                num2++;
                continue;
            }
            if (num2 == len2) {
                nums[m] = nums1[num1];
                num1++;
                continue;
            }
            if (nums1[num1] <= nums2[num2]) {
                nums[m] = nums1[num1];
                num1++;
                continue;
            }
            if (nums1[num1] > nums2[num2]){
                nums[m] = nums2[num2];
                num2++;
                continue;
            }

        }
        if (len % 2 == 0)
            return (nums[len / 2]+ nums[len / 2 - 1])/2.0;
        else
            return nums[len / 2];
    }
};


this file is added by shyshy
