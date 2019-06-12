class Solution {
    public int findLUSlength(String a, String b) {
        int aLen = a.length();
		int bLen = b.length();
		if(aLen != bLen){
			return Math.max(aLen, bLen);
		}else{
			if(a.equals(b)){
				return -1;
			}else{
				return aLen;
			}
		}
    }
}