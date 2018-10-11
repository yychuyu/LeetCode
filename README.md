//This file is added by 叶逸灵
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int len=nums.size();

    if(len == 0)
      return 0;
    int i = 0;

    for(int j = 1; j < len; ++j)
        if(nums[i] != nums[j])
            nums[++i] = nums[j];
    return i+1;
}
//我觉得题意没有说排除这种数据啊：0,1,0
/*int removeDuplicates(vector<int> &nums) {
    if(nums.size() <= 0)
        return 0;
        
    int len = nums.size(),t,flag;
    for(int i = 1; i < len; i++) {
        flag=0;
        for(int j=0;j<i;++j){
          if(nums[i]==nums[j]){
            t=nums[i];
            nums[i]=nums[len-1];
            nums[len-1]=t;
            --len;
            flag=1;
            break;
          }
        }
        if(flag==1)
        --i;
    }
    sort (nums.begin(), nums.begin()+len);
    return len;
}*/

int main(void) {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int len = removeDuplicates(nums);
    cout << "len: " << len << endl;
    for(int i=0 ; i<len ; ++i) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    return 0;
}
This file is added by Harry
