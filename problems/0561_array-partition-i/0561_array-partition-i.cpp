#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int sum=0;
    for(int i=0;i<nums.size();i+=2)
    {
    	sum+=nums[i];
	}
	return sum;
}
int main()
{
	int size,num;
	vector<int> nums;
	cin>>size;
	for(int i=0;i<size;i++)
		{
			cin>>num;
			nums.push_back(num);
		}
	int ans=arrayPairSum(nums);
	cout<<ans;	
	return 0;
}
