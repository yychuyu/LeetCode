class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int sum = 0;
        for (int num : A) {
            if (num % 2 == 0) {
                sum += num;
            }
        }
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int value = queries[i][0];
            int index = queries[i][1];
            if (A[index] % 2 == 0) {
                sum -= A[index];
            }
            A[index] += value;
            if (A[index] % 2 == 0) {
                sum += A[index];
            }
            result[i] = sum;
        }
        return result;
    }
}