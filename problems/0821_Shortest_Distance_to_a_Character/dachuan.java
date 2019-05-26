class Solution {
    public int[] shortestToChar(String S, char C) {
        int[] result = new int[S.length()];
        for (int i = 0; i < S.length(); i++) {
            if(S.charAt(i) == C){
                result[i] = 0;
                continue;
            }
            int left = 0;
            int right = 0;
            for (int l = i - 1; l >= 0; l--) {
                if(S.charAt(l) == C){
                    left = i - l;
                    break;
                }
            }
            for (int r = i + 1; r < S.length(); r++){
                if(S.charAt(r) == C){
                    right = r - i;
                    break;
                }
            }
            if(left == 0 || right == 0){
                result[i] = left == 0 ? right : left;
                continue;
            }
            result[i] = left < right ? left : right;
        }
        return result;
    }
}