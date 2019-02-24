#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NUMS 10	

int countPrimes(int n)
{
	if (n < 2)
		return 0;	//1不认为是质数

	//埃拉托色尼选筛法
	bool *isPrime = malloc(sizeof(bool) * n);	//创建一个数组用于记录对应的数字是否是质数
	memset((char *)isPrime, true, n);	//全部标记为质数
	int count = 1;	//从数字2开始，2是唯一的质数
	int i, j = 0;

	for(i = 3; i < n; i = i + 2) { // 只有奇数才有可能是质数
		if(isPrime[i]) { //从数字3开始，依次判断是否是质数
			count++;
			for(j = i; j < n; j = j+i)
				isPrime[j] = false;	// 该数是质数的话，它的倍数的数字都不是质数
		}
	}
	
	return count;
}

int main()
{
	printf("there are %d primes less than %d.\n", countPrimes(NUMS), NUMS);
}
