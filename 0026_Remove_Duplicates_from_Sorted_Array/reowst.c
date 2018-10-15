#include <stdio.h>
int RemoveDuplicates(int arr[],int n)
{
	int i=0,j=0;
	for(;j<n;j++)
	{
		if(arr[i]!=arr[j])
		{
			arr[++i]=arr[j];
		}
	}
	return ++i;
}
int main()
{
	int a[]={1};
	int m;
	m = RemoveDuplicates(a,sizeof(a)/sizeof(int));
	printf("result is:%d\n",m);
	return 0;
}
