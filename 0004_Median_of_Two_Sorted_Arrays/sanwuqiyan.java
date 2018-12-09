class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		int len1 = nums1.length, len2 = nums2.length, len3 = len1+len2;
		int[] res = new int[len1+len2];
		int j=0, index=0;
		for( int num : nums1 ) {
			while( j<len2 && num>nums2[j] ) {
				res[index++] = nums2[j++];
			}
			res[index++] = num;
		}
		for( ; j<len2; j++ ) {
			res[index++] = nums2[j];
		}
		
		int mi = len3 / 2;
		return len3 % 2 == 1 ? res[mi] : (res[mi - 1] + res[mi]) / 2.0;
    }
}
