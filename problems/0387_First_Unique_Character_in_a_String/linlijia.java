class Solution {
    public int firstUniqChar(String s) {
     
        if (s == null || s.length() == 0)
            return -1;
        
        int res = -1;
        int[] cnt = new int[26];
        
        for (char c : s.toCharArray()) {
            cnt[(int)c - 97]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (cnt[(int)s.charAt(i) - 97] == 1) {
                res = i;
                break;
            }
                
        }
        return res;
    }
}