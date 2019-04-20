/*******************************************************************
给定一个32位有符号整数，将整数中的数字进行反转。
比如321 -> 123
-321    ->  -123
假设只能存储32位有符号整数，其取值范围是[-2^31 - 2^31-1],溢出后返回0。
********************************************************************/

#include <iostream>
#include <windows.h>

using namespace std;

long int temp =0;
long int intmax = 0x7FFFFFFF;
long int intmin = 0x7FFFFFFF+1;

int reverse(long int x)
{
	while(x!=0)
	{
		if((temp > ((intmax)/10))||(temp < ((intmin)/10)))
			return 0;
		else
		{
			temp = temp*10 + x %10;
			x = x/10;
		}
		
	}
	return temp;
}
int main()
{
	{
		reverse(1253231121);
	}
	
	return 0;
	
}
