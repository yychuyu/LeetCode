
/*
使用后缀表达解，时间复杂度O(n),空间复杂度O(n)

wechat: fanshengluck2
email:  fansluck@qq.com
*/

class Solution {
public:
     int calculate(string s) {
       stack<int> backSS;
        char tempSign;
        int res,tempPush=0;
        int leftInt,rightInt;
        bool flag=false;
        for(int i=0;;i++){
            if (s[i]==' ') continue;
            else if (s[i]=='+'| s[i]=='-'){
                backSS.push(s[i]);
                flag=true; 
                 
            }
            else if (s[i]=='('){
                flag=false;
            }
            else if (s[i]==')'){
                // if (sign.pop()!='(')  return /'字符串违法'
                rightInt=backSS.top();
                backSS.pop();

                // if backSS.empty() return /'字符串违法'/
                if (backSS.empty()) {
                    backSS.push(rightInt);
                    continue;
                    }

                tempSign=backSS.top();  // if exception return /'字符串违法'/
                backSS.pop();
                
                leftInt=backSS.top();   // if exception return /'字符串违法'/
                backSS.pop();

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
                tempSign=backSS.top();
                backSS.pop();
                
                leftInt=backSS.top();
                backSS.pop();
               
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