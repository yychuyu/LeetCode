class Solution {
public:
    int lengthOfLastWord(string s) {
        int slength=s.size();
        int i=slength-1,length=0;
        if(s.size()==0)return 0;
        for(i;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                break;
            }
        }
        for(i;s[i]!=' '&&i>=0;i--)
        {
            length++;
        }
        return length;
    }
};
