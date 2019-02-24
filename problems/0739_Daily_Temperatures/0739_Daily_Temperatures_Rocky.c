#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int arr[temperaturesSize];
    int top = 0, i, j;
    int *result;
    result = (int *) malloc(sizeof(int) * temperaturesSize);

    result[temperaturesSize - 1] = 0;
    arr[0] = temperaturesSize - 1;

    for (i = temperaturesSize - 2; i >= 0; i--)
    {
        for (j = top; j >=0; j--) {
            if (temperatures[i] < temperatures[arr[j]]) {
                result[i] = arr[j] - i;
                top = j + 1;
                arr[top] = i;
                break;
            }
        }
        if (j < 0) {
            result[i] = 0;
            top = 0;
            arr[0] = i;
        }

    }

   *returnSize = temperaturesSize;
    return result;
}

int main(int argc, char ** argv) {
  int arr[] = {89,62,70,58,47,47,46,76,100,70};
  int returnSize;

  int *a = dailyTemperatures(arr, 10, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", a[i]);
  }
  free(a);
  return 1;
}
