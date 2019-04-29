#include <iostream>
#include <vector>
using namespace std;
//有问题
class Solution{
public:
    int trap(vector<int>& height){
        int size = height.size();
        int result = 0;
        if(size <= 0){
            return result;
        }//if
        int leftMax[size];
        int rightMax[size];
        leftMax[0] = 0;
        rightMax[size - 1] = 0;//
        //对于第i个元素，左右最大值
        for(int i = 1;i < size; ++i){
            leftMax[i] = max(leftMax[i-1],height[i-1]);
            rightMax[size-1-i] = max(rightMax[size-i],height[size-i]);

        } //for
        //最大集雨水
        int h;
        for(int i = 0; i < size;++i){
            h = min(leftMax[i],rightMax[i]);
            if(h > height[i]){
                result += h - height[i];
            }//if
        }//for
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << solution.trap(height) << endl;
    return 0;
}