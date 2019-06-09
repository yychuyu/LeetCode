#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        if (triangle.empty()) return 0;
        for (unsigned int i = triangle.size() - 1; i > 0; --i)
        {
            for (unsigned int j = 0; j < triangle[i - 1].size(); ++j)
            {
                triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
int main()
{
    // vector<vector<int>>& triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution method;
    // int result = method.minimumTotal(triangle);
    // cout << result;
    return 0;
}
