class Solution {
    public int[] sortedSquares(int[] A) {
        int[] B = new int[A.length];
        for (int i = 0; i < A.length; i++) {
            int m = A[i] * A[i];
            B[i] = m;
        }
        Arrays.sort(B);
        return B;
    }
}