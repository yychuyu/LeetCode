//
// Created by cxh on 18-12-19.
//
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::unordered_map;
vector<int> twoSum(vector<int> &vec, int target  )
{
    vector<int> result;
    unordered_map<int,int> mapping;

    int len = vec.size();
    for(int i=0;i<len;i++){
        mapping[vec[i]] = i;
    }

    for(int i=0;i<len;i++){
        int gap = target - vec[i];
        if(mapping.find(gap) != mapping.end() && mapping[gap] > i){
            result.push_back(i+1);
            result.push_back(mapping[gap]+1);
            break;
        }
    }
    return result;
}

int main(){
    vector<int> vec = {2,7,11,15};
    int target =  9;
    auto v = twoSum(vec,target);
    for(auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}

