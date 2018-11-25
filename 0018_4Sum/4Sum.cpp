//第16题的做法，44ms。
/*
  题目：
  给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
  使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

  注意：答案中不可以包含重复的四元组。
  
  示例：给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
  满足要求的四元组集合为：
  [
    [-1,  0, 0, 1],
    [-2, -1, 1, 2],
    [-2,  0, 0, 2]
  ]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rst;
        int len = nums.size();
        if(len < 4){        
            return rst;
        }
        if(len == 4){
            if( target==(nums[0]+nums[1]+nums[2]+nums[3]) ){
                rst.push_back( vector<int>{nums[0],nums[1],nums[2],nums[3]} );
            }  
            return rst;   
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<=len-4; i++){
            for(int j=i+1; j<=len-3; j++){
                int left=j+1, right=len-1;
                
                while(left<right){
                    int sum=nums[i]+nums[j]+nums[left]+nums[right];
                 
                    if(sum<target){
                        left++;
                    }else if(sum>target){
                        right--;
                    }else{//sum==0                    
                        rst.push_back( {nums[i],nums[j],nums[left],nums[right]} );                    
                        while( nums[left]==nums[left+1] ){
                            left++;
                        }
                        left++;                
                    }                   
                }                
                while( nums[j]==nums[j+1] ){               
                    j++;            
                }
            }//end of for(j)
            while( nums[i]==nums[i+1] ){      
              i++;           
            }               
        }//end of for(i)     
        
        return rst;
    }
}; 
