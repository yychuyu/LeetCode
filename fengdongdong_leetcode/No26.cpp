class Solution {
public:
    // ①使用STL：unique+erase
    // ②用两个哨兵，如下：
    int removeDuplicates(vector<int>& nums) {
        int first=0;
        int last=0;

        for(int i=1;i<nums.size();i++){
            if(nums[last]==nums[i]){
                last++;
                //to do ?
                if(i==nums.size()-1){
                    nums.erase(nums.begin()+first,nums.begin()+last);
                    break;
                }
            }
            else{
                if(last-first>=1){
                    nums.erase(nums.begin()+first,nums.begin()+last);
                    first=0;
                    last=0;
                    i=0;
                }
                else{
                    first=i;
                    last=i;
                }
            }
        }
        return nums.size();
    }
};
//for faster
static const auto __ = []()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
