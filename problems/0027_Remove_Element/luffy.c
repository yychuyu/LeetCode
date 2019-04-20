/*******************************************************************
给定一个数组nums和给一个值val,你需要原地移除数组中所有值为val的值，
返回移除后数组的新长度。
********************************************************************/

#include <iostream>
#include <windows.h>

using namespace std;



int removeElement(int* nums, int numsSize, int val) {
    int n = numsSize, i = 0;
    while(i < n){
        if (nums[i] == val){
           nums[i] = nums[n - 1];
		   n--;
        }
        else i++;
    }
    return n;
}
int main()
{
	int array[6]={1,2,3,2,3,2};
	int count = 6;
	int base = 2;
	int a =removeElement(array,count,base);
	cout<<"a 是:"<<a<<endl;		//输出运行时间
	system("pause");
	return 0;

}
