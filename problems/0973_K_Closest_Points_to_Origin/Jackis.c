/*
基于选择排序的方法，但该方法提交时显示超时
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        SelectSort(points, res, K);
        return res;
    }
    double Distance(vector<int> n)
    {
        return (double)n[0]*n[0] + (double)n[1]*n[1];
    }  
    void SelectSort(vector<vector<int>>& num, vector<vector<int>>& res, int K)
    {
        double min;
        int min_pos;
        int i, j;
        for(i=0; i<K; i++)
        {
            min = Distance(num[i]);
            min_pos = i;
            for(j=i+1; j<num.size(); ++j)
            {
                double num_j = Distance(num[j]);
                if(num_j < min)
                {
                    min = num_j;
                    min_pos = j;
                }
            }
            swap(num[i], num[min_pos]);
            res.push_back(num[i]);
        }
        
    }
};
/*
直接使用STL里的sort函数排序，只保留下标为[0--k-1]的数
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
       sort(begin(points), end(points), [this](auto& f, auto& s)
        {
            return (f[0]*f[0] + f[1]*f[1] < s[0]*s[0] + s[1]*s[1]); 
        });
        
       points.erase(begin(points) + K, end(points));
       return points;
    }
};
