class Solution {
    public int minDeletionSize(String[] A) {
     int num = 0;
		int outLen = A.length;
		int inLen = A[0].length();
		if (inLen == 1) {
			for (int i = 0; i < outLen - 1; i++) {
				if (A[i].toCharArray()[0] > A[i + 1].toCharArray()[0]) {
					num++;
					return num;
				}
			}
		}else{
			char[][] B = new char[outLen][inLen];
			//赋值
			for (int i = 0; i < outLen; i++) {
				char[] chars = A[i].toCharArray();
				for (int j = 0; j < chars.length; j++) {
					B[i][j] = chars[j];
				}
			}
			//比较
			outLoop:
			for (int i = 0; i < inLen; i++) {
				inLoop:
				for (int j = 0; j < outLen - 1; j++) {
					if(B[j][i] > B[j + 1][i]){
						num ++;
						break inLoop;
					}
				}
			}			
		}
		return num;   
    }
}