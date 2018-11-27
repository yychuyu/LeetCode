import java.util.Arrays;

/**
 *  created by LeiHauping on 2018/11/12
 */

public class Solution {
    public static void main(String[] args){
        int[] A={1,2,3,4,5,6,7,8,9};
        System.out.println(Arrays.toString(new Solution().sortArrayByParity(A)));
    }

    public int[] sortArrayByParity(int[] A) {
        int first=0;
        int last=A.length-1;
        int[] b=new int[A.length];
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0) {
                b[first] = A[i];
                first++;
            }else {
                b[last]=A[i];
                last--;
            }
        }
        return b;
    }
}
