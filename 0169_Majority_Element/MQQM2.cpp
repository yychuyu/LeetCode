/*
  题目：
  给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
  你可以假设数组是非空的，并且给定的数组总是存在众数。
  
  做法：摩尔投票法。
  每次从数组中找出一对不同的元素，将它们从数组中删除，直到遍历完整个数组。
  由于这道题已经说明一定存在一个出现次数超过一半的元素，所以遍历完数组后数组中一定会存在至少一个元素。
  
  参考：
  https://blog.csdn.net/qjh5606/article/details/81358892
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur_maj = 0;    //当前所认为的众数
        int cnt = 0;        //所认为的众数的投票(遇到一样的元素，票数加一，否则减一)
        for(int num : nums){
            if(cnt == 0){   //次数为0，重新设置众数，继续“投票”
                cur_maj = num;
                cnt++;
            }else{
                num == cur_maj ? cnt++ : cnt--;                
            }
        }
        
        return cur_maj;
    }
};
