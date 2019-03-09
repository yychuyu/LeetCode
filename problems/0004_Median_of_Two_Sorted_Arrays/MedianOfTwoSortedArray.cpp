class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();
        if (nums1.empty()) {
            if (n%2 != 0)
                return 1.0*nums2[n/2];
            return (nums2[n/2]+nums2[n/2-1])/2.0;
        }
        if (nums2.empty()) {
            if (m%2 != 0)
                return 1.0*nums1[m/2];
            return (nums1[m/2]+nums1[m/2-1])/2.0;
        }

        int total = (m+n+1)/2;
        int total2 = (m+n+2)/2;

        return (find_kth(nums1,0,nums2,0,total)+find_kth(nums1,0,nums2,0,total2))/2.0;
    }
    double find_kth(vector<int> a, int a_begin, vector<int> b, int b_begin, int k) {
        if (a_begin > a.size()-1)
            return b[b_begin+k-1];
        if (b_begin > b.size()-1)
            return a[a_begin+k-1];
        if (k == 1)
            return min(a[a_begin],b[b_begin]);

        int mid_a = INT_MAX;
        int mid_b = INT_MAX;
        if (a_begin+k/2-1 < a.size())
            mid_a = a[a_begin+k/2-1];
        if (b_begin+k/2-1 < b.size())
            mid_b = b[b_begin+k/2-1];

        if (mid_a < mid_b)
            return find_kth(a,a_begin+k/2,b,b_begin,k-k/2);
        return find_kth(a,a_begin,b,b_begin+k/2,k-k/2);
    }
};
