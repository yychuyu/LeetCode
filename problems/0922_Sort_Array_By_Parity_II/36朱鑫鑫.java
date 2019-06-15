class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int oIndex=0,eIndex=0;
        int odd[] = new int[A.length/2];
        int even[] = new int[A.length/2];
        
        for(int i : A){
            if(i % 2 == 0){
                even[eIndex++] = i;
            }else{
                odd[oIndex++] = i;
            }
        }
        oIndex=0;
        eIndex=0;
        
        for(int i=0;i<A.length;i++){
            if(i%2==0){
                A[i]=even[eIndex++];
            }else{
                A[i]=odd[oIndex++];
            }
        }
        return A;
        
    }
}