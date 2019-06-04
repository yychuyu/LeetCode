#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxarea = 0;
        
        while(left != right){
            maxarea = max(min(height[left],height[right]) * (right-left) , maxarea);
            
            (height[left] < height[right]) ? ++left : --right;
            
        }
        return maxarea;
	
	return 0;
} 
