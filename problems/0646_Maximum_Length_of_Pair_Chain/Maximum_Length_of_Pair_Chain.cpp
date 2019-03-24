class Solution {
public:
static bool cmp(vector<int> &a, vector<int> &b) {
	return a[1] < b[1];
}
int findLongestChain(vector<vector<int>>& pairs) {
	sort(pairs.begin(), pairs.end(), cmp);
	int end = INT_MIN;
	int res = 0;
	for (auto pair : pairs) {
		if (pair[0] > end) {
			res++;
			end = pair[1];
		}
	}
	return res;
}
};