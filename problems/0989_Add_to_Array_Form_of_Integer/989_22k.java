class Solution {
    public List<Integer> addToArrayForm(int[] A, int k) {
        List<Integer> res = new LinkedList<>();
        for(int i=A.length-1;i>=0;i--){
            res.add(0 ,(A[i] + k) % 10);
            k=(k+A[i])/10;
        }
        while(k>0){
            res.add(0,k%10);
            k = k/10;
        }
        return res;
    }
}