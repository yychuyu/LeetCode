/**
 * Created by Json Wan on 2018/11/12.
 */
public class wanxu_pursue_0905 {

    //ac,0.8153
    public int[] sortArrayByParity(int[] A) {
        int l=0;
        int r=A.length-1;
        int tmp=A[l];
        while(l<r){
            while(l<r&&A[r]%2!=0)
                r--;
            if(l<r){
                A[l]=A[r];
                l++;
            }
            while(l<r&&A[l]%2==0)
                l++;
            if(l<r){
                A[r]=A[l];
                r--;
            }
        }
        A[l]=tmp;
        return A;
    }

    public int[] bestSortArrayByParity(int[] A) {
        int i=0, j= A.length - 1;
        while(i < j)
        {
            if(A[i] % 2 == 1 && A[j] %2 == 0)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
            }
            else if(A[i] % 2 == 0)
            {
                i++;
            }
            else if(A[j] % 2 == 1)
            {
                j--;
            }
        }
        return A;
    }

    public static void main(String[] args) {
        int[] b=new wanxu_pursue_0905().sortArrayByParity(new int[]{3,1,2,4});
        for (int i = 0; i < b.length; i++) {
            System.out.print(b[i]+" ");
        }
    }
}
