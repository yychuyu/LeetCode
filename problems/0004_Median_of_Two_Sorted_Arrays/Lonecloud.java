class Lonecloud {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len=nums1.length + nums2.length;
        int[] nums = new int[len];
        System.arraycopy(nums1,0, nums, 0,nums1.length);
        System.arraycopy(nums2,0, nums, nums1.length, nums2.length);
        Arrays.sort(nums);
        return len%2==0?((nums[len/2]+nums[len/2-1])/2.0):nums[len/2];
    }
}
