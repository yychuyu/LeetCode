#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

//DP 
int integerBreak(int n) 
{
	int nums[n+1];
	memset(nums,0,sizeof(nums));
	nums[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			nums[i]=max(nums[i],max(j*nums[i-j],j*(i-j)));
		}
	}
	return nums[n];
}

int main()
{
	int nums;
	cin>>nums;
	int ans=integerBreak(nums); 
	cout<<ans<<endl;
	return 0;
}
