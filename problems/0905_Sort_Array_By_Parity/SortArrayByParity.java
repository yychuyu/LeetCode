package com.company;

public class SortArrayByParity {
    public int[] sortArrayByParity(int[] A) {
        if(A == null || A.length == 0 || A.length == 1)
            return A;
        int i = 0;
        int j = A.length - 1;
        while(i < j){
            if(i < j && A[i] % 2 == 0) i++;
            if(i < j && A[j] % 2 == 1) j--;
            swap(A, i, j);
        }
        return A;
    }

    private void swap(int[] A, int i, int j){
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}
