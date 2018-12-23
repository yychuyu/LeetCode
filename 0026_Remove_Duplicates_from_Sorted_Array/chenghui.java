public class Remove_Duplicates_from_Sorted_Array {
	public int removeDuplicates(int[] A) {
        if(A.length == 0 || A == null)
            return 0;
        
        int len = 1;
        for(int index = 1; index < A.length; index++){
            if(A[index] != A[index-1]){
                if(A[index] != A[len])
                    A[len] = A[index];
                len++;
            }
        }
        return len;
    }
}This file is added by Chenghui
