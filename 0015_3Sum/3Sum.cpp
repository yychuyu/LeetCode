//第16题的做法，576ms，效率不高。
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
    static bool isIn(vector<vector<int>>& v, vector<int>& e){
        for(int i=0; i<v.size(); i++){           
            if( (e[0]==v[i][0]) && (e[1]==v[i][1]) && (e[2]==v[i][2]) ){             
                return true;        
            }
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rst;
        int len = nums.size();
        if(len < 3){
            return rst;
        }
        if(len==3){
            if( 0==(nums[0]+nums[1]+nums[2]) ){
                rst.push_back( vector<int>{nums[0],nums[1],nums[2]} );
            }  
            return rst;                      
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<len-2; i++){
            int left=i+1, right=len-1;
            
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                
                if(sum<0){
                    left++;
                }else if(sum>0){
                    right--;
                }else{//sum==0
                    vector<int> tmp={nums[i],nums[left],nums[right]};
                    if( !isIn(rst,tmp) ){
                        rst.push_back(tmp);
                    }
                    left++;
                }                                           
            }            
        }//end of for()

        return rst;        
    }
};
