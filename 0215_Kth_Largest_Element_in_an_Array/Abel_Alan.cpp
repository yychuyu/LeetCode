class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int high = nums.size();
        int low = 0;
        while (low < high) {
            int i = low;
            int j = high-1;
            int pivot = nums[low];
            while (i <= j) {
                while (i <= j && nums[i] >= pivot)
                    i++;
                while (i <= j && nums[j] < pivot)
                    j--;
                if (i < j)
                    swap(nums[i++],nums[j--]);
            }
            swap(nums[low],nums[j]);
 
            if (j == k-1)
                return nums[j];
            else if (j < k-1)
                low = j+1;
            else
                high = j;
        }
    }
};
