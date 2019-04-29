class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index1 = m - 1, index2 = n - 1;
        while(index2 >= 0) {
            if(index1 < 0) {
                for(int i = index2; i >= 0; i--)
                    nums1[i] = nums2[i];
                break;
            }
            if(nums1[index1] < nums2[index2]) {
                nums1[index1 + index2 + 1] = nums2[index2];
                index2--;
            } else {
                nums1[index1 + index2 + 1] = nums1[index1];
                index1--;
            }
        }
    }
}
