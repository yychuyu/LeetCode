/*
  题目：
  给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。找到所有出现两次的元素。
  你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

  参考：
  https://blog.csdn.net/hhh0209/article/details/80096606?utm_source=blogxgwz2
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> rst;
        if( nums.empty() ){
            return rst;
        }
        
        for(int i=0; i<nums.size(); i++){
            int idx=abs(nums[i])-1;//本应判断元素abs(num[i])是否重复，因为不能用额外空间，这里变相地判断“将其作为下标的元素”是否重复。
            if( nums[idx]>0 ){   
                nums[idx] = -nums[idx];    
            }else{
                rst.push_back(idx+1);
            }            
        }  
        
        return rst;
    }
};
