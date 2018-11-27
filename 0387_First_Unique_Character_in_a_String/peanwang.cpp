class Solution {
public:
    int firstUniqChar(string s) {
        int alp[26],len = s.size();
        fill(begin(alp),end(alp),-1);
        for(int i=0;i<len;i++){
            if(alp[s[i]-'a'] ==-1){
                alp[s[i]-'a']=i;
            }
            else if(alp[s[i]-'a']!=len){   //alp[s[i]-'a']!=len mean first repeat,alp[s[i]-'a']==len mean repeats many times
                alp[s[i]-'a']=len;
            }
        }
        int min=len;
        bool flag=false;     //have no repeat ?
        for(int i=0;i<26;i++){
            if(alp[i]!=len && alp[i]!=-1){        //No repeat and have apperance
                if(min >alp[i])
                    min = alp[i];
                flag = true;
            }
        }
        return flag?min:-1;
    }
};