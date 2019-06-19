class Solution {
    public String toLowerCase(String str) {
        
        String ans="";
        for(int i=0;i<str.length();i++)
        {
            char a=str.charAt(i);
            a=tolowercase(a);
            ans+=a;
        }
        return ans;
    }
    private char tolowercase(char t)
    {
        if(t>='A' && t<='Z')
        {
            t=(char)(t+32);
        }
        return t;
    }
    
}