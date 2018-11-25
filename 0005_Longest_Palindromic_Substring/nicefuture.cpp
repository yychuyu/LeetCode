class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 0) return "";
        if (s.size() == 1) return s;
		int i = 0, j = 1, m, n, len;
		int result[3]={0, 0, 1};
		// cycle
		while (s[j] != '\0') {
			// i compare with j
			if (s[i] == s[j]) {
				/*printf("%c equals %c\n", s[i], s[j]);*/
				m = i;
				n = j;
				len = 2;
				while (m > 0 && s[n+1] != '\0' && s[m-1] == s[n+1]) {  // expand
					m--;
					n++;
					len += 2;
				}
				if (len > result[2]) {
					result[0] = m;
					result[1] = n;
					result[2] = len;
				}
			}
			// i compare with j+1
			if (s[i] == s[j+1]) {
				/*printf("%c equals %c\n", s[i], s[j+1]);*/
				m = i;
				n = j+1;
				len = 3;
				 while (m > 0 && s[n+1] != '\0' && s[m-1] == s[n+1]) {  // expand
					m--;
					n++;
					len += 2;
				}
				 if (len > result[2]) {
					result[0] = m;
					result[1] = n;
					result[2] = len;
				 }
			}
			i++;
			j++;
			//printf("result: %d %d %d\n", result[0], result[1], result[2]);
		}

		return s.substr(result[0], result[2]);
    }
};
