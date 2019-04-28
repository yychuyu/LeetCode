#include <iostream>
#include <cmath>
using namespace std;
int countPrimes(int n) {
	int count = 0;
	if(n == 1)
		return 0;
	for(int i = 2; i < n; i++ ){    // 从2到 n 遍历
		int m = sqrt(i);
		for(int j = 2; j <= m; j++){     //判断一个数是否为质数   j<m ，出错：不熟悉for循环的执行顺序 
			 if(i%j == 0){             
				count++;               //不是质数 count 计数加一 
				break; 
			}	
		}
	}
	return n-2-count;		   // 总数减去合数的数量 
}
int main(){
	int a;
	a = countPrimes(10);
	cout << a;
	return 0;
	
} 
