#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        int n = heights.size();
        int res = 0;
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < heights.size(); ++i) {
            while(s.top() != -1 && heights[s.top()] > heights[i]) {
                int x = s.top();
                s.pop();
                res = max(res, heights[x] * (i - s.top() - 1));
            }
            s.push(i);
        }

        return res;
    }

    // O(n ^ 2)
    /*
    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            // 注意這里要先判斷是否到尾了再判斷後面 ||
    條件，否則在Leetcode上會超出範圍報heap Error if (i == heights.size() - 1 ||
    heights[i] > heights[i + 1]) { int m = heights[i]; for (int j = i; j >= 0;
    --j) { m = min(m, heights[j]); res = max(res, (i - j + 1) * m);
                }
            }
        }
        return res;
    }
    */
};

void test_case_1() {
    vector<int> heights{2, 1, 5, 6, 2, 3};
    assert(Solution().largestRectangleArea(heights) == 10);
}

int main(void) {
    test_case_1();

    return 0;
}
