#include <stdio.h>

// 理解错了题意，这个函数写成了计算无连续重复字符的最长子串长度
int lengthOfLongestSubstringWithoutContinuousCharacter(char* s) {
	int i = 1, iMax = 0;
	while (*(++s) != '\0'){
		if (*(s - 1) == *s){
			
			i = 1;
		}
		else{
			i++;
		}
		iMax = iMax < i ? i : iMax;
	}
	return iMax;
}

// 先蛮力解决
int checkRepeat(char* s, int p, int q){
	//s[p, p+q)为需要检查重复的字符串
	//返回的是s[p, p+q)从首字符开始的无重复子串的最大长度
	int i = 0;
	int a[200] = { 0 };
	for (i = 0; i < q; i++){
		if (a[(int)(s[p + i])]){
			break;
		}
		else{
			a[(int)(s[p + i])]++;
		}
	}
	return i;
}
int lengthOfLongestSubstring(char* s) {
	int i = 0, j = 2, max = 0, l = 0;

	if (s[0] == '\0') 
		return 0; 
	else if ((s[1] == '\0')) 
		return 1;
	while (1){
		// 判断起始字符串是否为\0
		if (s[i + 1] != '\0'){
			j = 1;
			while (1){
				if (s[i + j-1] != '\0'){
					l = checkRepeat(s, i, j);
					max = max < l ? l : max;
					if (l < j) break;
					j++;
				}
				else{
					break;
				}
			}
			i++;
		}
		else{
			break;
		}
	}
	return max;
}

int main(){
	int l=0;
	char s[] = "abcabcbb";
	l = lengthOfLongestSubstring(s);
	return l;
}
