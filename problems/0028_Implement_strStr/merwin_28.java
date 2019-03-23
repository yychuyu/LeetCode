class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.length()==0){
            return 0;
        }
        if(needle.length() > haystack.length() || haystack.length()==0){
            return -1;
        }
        char [] a = haystack.toCharArray();
        char [] b = needle.toCharArray();
        for(int i=0; i<= a.length-b.length; i++){
            if(a[i] == b[0]){
                int i1 = i;
                int j=0;
                for(;j<b.length;){
                    if(a[i1] != b[j]){
                        break;
                    }
                    i1++;
                    j++;
                }
                if(j >= b.length){
                    return i;
                }
            }
        }
        return -1;
    }
}
