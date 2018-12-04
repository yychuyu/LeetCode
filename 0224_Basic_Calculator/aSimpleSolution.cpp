
/*
使用后缀表达解，时间复杂度O(n),空间复杂度O(n)

wechat: fanshengluck2
email:  fansluck@qq.com
*/

class Solution {
public:
    int calculate(string s) {
       return  backStone(s);
    }
    int backStone(string s){
        stack<int> backSS;
        stack<char> sign;
        char tempSign;
        int res,tempPush=0;
        int leftInt,rightInt;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            if (s[i]==' ') continue;
            
            else if (s[i]=='+'| s[i]=='-'){
                sign.push(s[i]);
                flag=true; 
                 
            }
            else if (s[i]=='('){
                sign.push(s[i]);
                flag=false;
            }
            else if (s[i]==')'){
                // if (sign.pop()!='(')  return /'字符串违法'/
                sign.pop();
                if (sign.empty()) continue;
                
                rightInt=backSS.top();
                backSS.pop();
                // if backSS.empty() return /'字符串违法'/
                leftInt=backSS.top();
                backSS.pop();
                tempSign=sign.top();
                sign.pop();
                if (tempSign=='-') 
                    res=leftInt-rightInt;
                else res=leftInt+rightInt;
                backSS.push(res);
                flag=true;

                }
            else if (s[i]=='\0'){
                break;
            }
             else if(flag){
                // rightInt=backSS.top();
                // backSS.pop();
                tempPush=tempPush*10+(s[i]-48);
                if (s[i+1]>='0'&& s[i+1]<='9')
                    continue;
                else rightInt=tempPush;
                // if backSS.empty() return /'字符串违法'/
                leftInt=backSS.top();
                backSS.pop();
                tempSign=sign.top();
                sign.pop();
                if (tempSign=='-') 
                    res=leftInt-rightInt;
                else res=leftInt+rightInt;
                backSS.push(res);
                tempPush=0;
                flag=true;
                }
            else{
                tempPush=tempPush*10+(s[i]-48);
                if (s[i+1]>='0'&& s[i+1]<='9')
                    continue;
                else backSS.push(tempPush);
                tempPush=0;
            }
            }
        // if (s[i-1]=='+'|s[i-1]=='-'|s[i-1]=='('|s[i-1]=='-') return /'字符串违法'/
        res=backSS.top();
        backSS.pop();
        // if (!backSS.empty()) return /'字符串违法'/
        return res;
        }
};