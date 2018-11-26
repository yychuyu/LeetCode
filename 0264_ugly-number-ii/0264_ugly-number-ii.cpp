#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//动态规划解决
int nthUglyNumber(int n) {
	int num[n];
    int i=1;
    num[0]=1;
    int ind2,ind3,ind5;
    ind2=ind3=ind5=0;
    while(i<n)
    {
    	num[i]=min(2*num[ind2],min(3*num[ind3],5*num[ind5]));
    	if(num[i]==2*num[ind2])
    		ind2++;
    	if(num[i]==3*num[ind3])
    		ind3++;
    	if(num[i]==5*num[ind5])
    		ind5++;
    	i++;
	}
	return num[n-1];
}

//暴力解法，TLE 
 int nthUglyNumber1(int n,int *num) {
 	int max=INT_MAX;
 	num[1]=1;
 	int flag=1;
 	int i,count,N; 
 	for(count=i=2;count<=1690&&i<=max;i++)
 	{
 		flag=1;
 		N=i;
 		while(N!=1)
 		{
 			if(N%2==0)
 				N/=2;
 			else if(N%3==0)
 				N/=3;
 			else if(N%5==0)
 				N/=5;
 			else
 			{
 				flag=0;
 				break;
 			}
 		
		 }
		 if(flag)
		 {
		 	num[count++]=i;
		 } 
	}
     return num[n];  
}
int main()
{
	int n;
	cin>>n;
	cout<<nthUglyNumber(n)<<endl;
	return 0;
}
