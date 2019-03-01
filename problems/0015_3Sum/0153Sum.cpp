class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector< vector<int> > ret;
    int len=nums.size();
    sort(nums.begin(), nums.end());  
    for(int left=0;left<len-2;left++){ 
        int mid=left+1;
        int right=len-1;
        int tmp=0-nums[left];
        
        if (nums[left] > 0)
            break;

        if (&& nums[left]==nums[left-1]){
            
            continue;
            }
        
        while(mid<right){
            
            if(nums[mid]+nums[right]<tmp){
                mid++;
            }else if(nums[mid]+nums[right]>tmp){
                right--;
            }
            else{
                ret.push_back({nums[left],nums[mid],nums[right]});
                mid++;
                right--;
                //跳过重复的部分
                while(mid<right&&nums[mid]==nums[mid-1]){
                    mid++;
                } 
                while(mid<right&&nums[right]==nums[right+1]){
                    right--;
                }
            }
            
        }
        
    }
    
    return ret;
    }
};