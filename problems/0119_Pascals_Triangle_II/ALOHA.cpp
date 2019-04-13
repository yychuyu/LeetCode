class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; ++i)
        {
            /* 从右往左求 */
            for(int j = i; j >= 0; --j)
            {
                int n = 0;
                n += (j > 0) ? res[j - 1] : 0;
                n += (j < i) ? res[j] : 0;
                res[j] = n;
            }
        }
        return res;
    }
};
