/*
  题目：
  给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
  你可以假设数组是非空的，并且给定的数组总是存在众数。
  
  做法：遍历一趟，记录各个元素出现的次数。
  
  参考：
  https://blog.csdn.net/qjh5606/article/details/81358892
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
             m[nums[i]]++;
        }
        
        int rst;
        for(auto it : m){
            if(it.second > nums.size() / 2){
                rst = it.first;
                break;
            }
        }
        
        return rst;
    }
};

/*
还有一种(最简单的)做法：因为众数出现的次数过半了，所以排序后，最中间的值必定是众数。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
*/
