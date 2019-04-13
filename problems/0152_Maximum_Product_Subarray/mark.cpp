// 1.找出相乘最大的连续子序列

/*
// 方法1 ： 暴力解法，找出所有子序列相乘， 但是很慢
// time：O(n^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int temp;
        for(int i = 0; i < nums.size(); ++i){
            temp = nums[i];
            max = temp > max ? temp : max;
            for(int j = i+1; j < nums.size(); ++j){
                temp *= nums[j];
                max = temp > max ? temp : max;
            }
        }
        
        return max;
    }
};
*/

/*
方法2： 动态规划思想。最大值可能是 （当前已知最大值，最小值*当前值， 当前值） 三个中的一个。所以用两个数组维护最大值和最小值，不断比较，得出结果
当前的最大值等于已知的最大值、最小值和当前值的乘积，当前值，这三个数的最大值。
当前的最小值等于已知的最大值、最小值和当前值的乘积，当前值，这三个数的最小值。
结果是最大值数组中的最大值。
*/

// Time : O(n) 8 ms
// Space: O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> maxN(len);
        vector<int> minN(len);
        int res = maxN[0] = minN[0] = nums[0];
        
        for(int i=1; i < len; ++i){
            maxN[i] = max(nums[i], max(nums[i]*maxN[i-1], nums[i]*minN[i-1]));
            minN[i] = min(nums[i], min(nums[i]*maxN[i-1], nums[i]*minN[i-1]));
            res = max(maxN[i], res);
        }
        
        return res;
    }
};

