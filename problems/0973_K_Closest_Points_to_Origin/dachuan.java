class Solution {
    public int[][] kClosest(int[][] points, int K) {
        int len = points.length;
        int[] sum = new int[len];
        for (int i = 0; i < len; i++) {
            sum[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        }
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - 1 -i ; j++) {
                if (sum[j] > sum[j + 1]) {
                    int tmp = sum[j];
                    sum[j] = sum[j + 1];
                    sum[j + 1] = tmp;
                    int[] pointTmp = points[j];
                    points[j] = points[j + 1];
                    points[j + 1] = pointTmp;
                }
            }
        }
        int[][] result = new int[K][2];
        for (int i = 0; i < K; i++) {
            result[i][0] = points[i][0];
            result[i][1] = points[i][1];
        }
        return result;
    }
}