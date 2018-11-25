class Solution {
public:
    int myAtoi(string str) {
        int i=0,len = str.size();
        long long result=0;
        while(i<len && str[i]==' ')
            i++;
        bool flag = true;
        if(str[i]=='+' || str[i]=='-')
            flag = str[i++] =='+'?true:false;
        else if(!isdigit(str[i]))
            return 0;
        while(i<len && isdigit(str[i])){
            result = result*10 + str[i]-'0';
            if(result >INT_MAX)
                break;
            i++;
        }
        result *= flag?1:-1;
        if(result>INT_MAX)
            return INT_MAX;
        else if(result<INT_MIN)
            return INT_MIN;
        else
            return result;
    }
};