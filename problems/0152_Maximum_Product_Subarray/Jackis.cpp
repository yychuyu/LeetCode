//1
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //dp Solution
        int n = nums.size();
        vector<int> f(n);      //max
        vector<int> g(n);      //min
        int res;
        res = f[0] = g[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            f[i] = max(max(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i]);
            g[i] = min(min(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i]);
            if(f[i] > res)
                res = f[i];
        }
        return res;
    }
};

//2
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //dp Solution
       int res=nums[0], mx=res, mn=res;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                mx = max(mx*nums[i], nums[i]);
                mn = min(mn*nums[i], nums[i]);
            }
            else 
            {
                int tmp = mx;
                mx = max(mn*nums[i], nums[i]);
                mn = min(tmp*nums[i], nums[i]);
            }
            res = max(res, mx);
        }
        return res;
    }
};
//3
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //dp Solution
       int res=nums[0], mx=res, mn=res;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] < 0)
                swap(mx, mn);
            mx = max(mx*nums[i], nums[i]);
            mn = min(mn*nums[i], nums[i]);
            res = max(res, mx);
        }
        return res;
    }
};
//4
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int res=nums[0], prod=1, n=nums.size();
        for(int i=0; i<n; i++)
        {
            res = max(res, prod*=nums[i]);
            if(nums[i] == 0)
                prod = 1;
        }
        prod = 1;
        for(int i=n-1; i>=0; i--)
        {
            res = max(res, prod*=nums[i]);
            if(nums[i] == 0)
                prod = 1;
        }
        return res;
    }
};