class NumArray {
public:
    NumArray(vector<int>& nums) {
       if(!nums.empty())
       {
            _arr.push_back(nums[0]);
            for(int i = 1;i<nums.size();++i)
            {
                _arr.push_back(_arr.back()+nums[i]);
            }
       }
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
        {
            return _arr[j];
        }
        return _arr[j]-_arr[i-1];
    }
public:
    vector<int> _arr;
};