#include <iostream>
using namespace std;

/*
对于每一个位置，以该位置为对称轴找回文字符串；保留最大
*/
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 0) {
			return "";
		}
		int maxlength = 0;
		string maxString = s.substr(0, 1);
		for (int i = 0; i < s.length() - 1; i++) {
			if (i == 0) {
				if (s[0] == s[1]) {
					maxlength = 2;
					maxString = s.substr(0, 2);
				}
				continue;
			}

			string str = searchPalindrome(s, i);
			int length = str.length();
			if (length > maxlength) {
				maxlength = length;
				maxString = str;
			}
		}
		return maxString;
	}

	/*
	1 <= start< s.length()-1
	在s中，以下标start为对称轴，向左向右找回文字符串
	*/
	string searchPalindrome(string s, int start) {
		int length = 0, maxlength = 0;
		string str = s.substr(start,1);
		// bb型回文
		if (s[start] == s[start + 1]) {
			maxlength = 2;
			for (int i = 1; start + i + 1 < s.length() && start - i >= 0; i++) {
				if (s[start + i + 1] == s[start - i]) {
					maxlength += 2;
				}
				else {
					break;
				}
			}
			str = s.substr(start - maxlength / 2 + 1, maxlength);
		}
		// aba型回文
		if (s[start - 1] == s[start + 1]) {
			length = 3;			
			for (int i = 2; start + i < s.length() && start - i >= 0; i++) {
				if (s[start + i] == s[start - i]) {
					length += 2;
				}
				else {
					break;
				}
			}
			maxlength = maxlength > length ? maxlength : length;
			str = s.substr(start - (maxlength - 1) / 2, maxlength);
		}
		return str;
	}
};

/*
	大佬4ms，思路与上班类似，只是更简洁，更高效
*/
class Solution2 {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		int i = 0;
		int start;
		int end;
		int tmp_len;
		int max_len = 1;
		int pos = 0;
		while (i < n) {
			start = i;
			end = i;
			// 跳过重复的字符串
			while (end < n - 1 && s[end + 1] == s[end]) {
				++end;
			}
			i = end + 1; // 更新i
						 // 两边扩张，注意此时start和end标记的分别是重复串的起始点
			while (start > 0 && end < n - 1 && s[start - 1] == s[end + 1]) {
				--start;
				++end;
			}
			tmp_len = end - start + 1;
			if (tmp_len > max_len) {
				max_len = tmp_len;
				pos = start;
			}
		}
		return s.substr(pos, max_len);
	}
};

int main() {
	Solution s;
	string str = s.longestPalindrome("cbbd");
}
