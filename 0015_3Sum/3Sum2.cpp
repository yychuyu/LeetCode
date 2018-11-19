//第16题的做法，96ms。
/*
  题目：
  给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 
  注意：答案中不可以包含重复的三元组。
  
  例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
  满足要求的三元组集合为：
  [
    [-1, 0, 1],
    [-1, -1, 2]
  ]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        int len = nums.size();
        if(len < 3){
            return rst;
        }
      
        sort(nums.begin(),nums.end());//排序后相同的元素会相邻，所以“左右比较”就可以排除重复。
        
        for(int i=0; i<len-2; i++){
            int left=i+1, right=len-1;
        
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum+nums[i]==0){                    
                    vector<int> tmp={nums[i],nums[left],nums[right]};                    
                    rst.push_back(tmp);//这两句等于rst.push_back( {nums[i],nums[left],nums[right]} );                    
                    while( nums[left]==nums[left+1] ){//发现了相同的元素
                        left++;
                    }
                    left++;
                    continue;
                }
                if(sum+nums[i]<0){
                    left++;
                }else{
                    right--;
                } 
            }
            while( nums[i]==nums[i+1] ){//发现了相同的元素
                i++;
            }                
        
        }//end of for()
        
        return rst;
    }
};
