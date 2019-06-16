#include <string.h>
#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;

//思路一：
int Decodings(char *s, int size){
	int count = 0;
	if ('0' == s[0])
		return count;
	if (0 == size || 1 == size)
		return ++count;
	if ('0' != s[0])
		count += Decodings(s + 1, size - 1);
	if ('1' == s[0] || ('2' == s[0] && '6' >= s[1]))
		count += Decodings(s + 2, size - 2);
	return count;
}

int numDecodings(char *s) {
	int size = strlen(s);
	return Decodings(s, size);
}


//思路二：dp，类似爬楼梯 f(n)=f(n-1)+f(n-2)

#define CONDITION	'1' == s[i] || ('2' == s[i] && '6' >= s[i+1])
class Solution {
public:
	int numDecodings(string s) {
		if ('0' == s[0])	return 0;
		const int size = s.size();
		if (1 == size)	return 1;
		vector<int> steps(size, 0);
		int i = size - 1;
		steps[i] = ('0' != s[i]) ? 1 : 0;
		if ('0' != s[--i])
			steps[i] = steps[i + 1] + ((CONDITION) ? 1 : 0);
		cout << steps[i + 1] << ' ' << steps[i] << endl;
		for (--i; i >= 0; --i)
		{
			int step_one = steps[i + 1];
			step_one = ('0' != s[i]) ? steps[i + 1] : 0;						//若这一步为'0'，表示无法以单步向下走
			int step_two = steps[i + 2];
			step_two = (CONDITION) ? steps[i + 2] : 0;	//若不为'1'或'2'，表示无法两步向下
			steps[i] = step_one + step_two;
		}
		return steps[0];
	}
};

int main()
{
	string s {'1','2','1'};
	Solution sol;
	cout << sol.numDecodings(s) << endl;
	system("pause");
	return 0;
}