int myAtoi(char* str) {//遍历解决
    int fu=1;
long long num=0;
char * cur = str;

if(str==NULL){
    return 0;
}
while(*cur==' '){
    cur++;
}
while(*cur=='-'||*cur=='+'){
    if((*cur)=='-'){
        fu=-1;
        cur++;
        break;
    }else{
        cur++;
        break;
    }
}

while(*cur >='0' && *cur <='9'){
    num = (num * 10) + *cur - '0';
    cur ++;
    if(num * fu<=INT_MIN)
        return INT_MIN;
    if(num * fu>= INT_MAX)
        return INT_MAX;
}

return num * fu;
}