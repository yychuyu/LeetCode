class Solution {
    public int repeatedNTimes(int[] A) {
        Arrays.sort(A);
		int num = 0;
		int tmp = 0;
		int len = A.length;
		for (int i = 0; i < len; i++) {
			if (A[i] != tmp) {
				if (num == len / 2) {
					return A[i - 1];
				}
				num = 1;
				tmp = A[i];
			}else{
				num++;
			}
		}
		return A[len - 1];
    }
}