

#include <iostream>
#include <windows.h>

using namespace std;



int* plusOne(int *digits, int digitsSize) {
    int returnSize;
	int carry = 1;
    for (int i = 0; i < digitsSize; i++){
        if (digits[i] != 9){
            carry = 0;
            break;
        }
    }
    int* plusone = (int*)malloc(sizeof(int)*(digitsSize+carry));
    if (carry){
        plusone[0] = 1;
    }
    int p = 1;
    for (int i = digitsSize - 1; i >= 0; i--){
        plusone[i+carry] = digits[i] + p;
        if (plusone[i+carry] > 9){
            plusone[i+carry] -= 10;
            p = 1;
        }
        else{
            p = 0;
        }
    }
    returnSize = digitsSize+carry;
    return plusone;
}


int main()
{
	int array[6]={1,2,3,2,3,2};
	int* plusOne(array, 6);
	system("pause");
	return 0;

}
