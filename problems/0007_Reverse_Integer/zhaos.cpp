/*by zhaos wx:ÕÅÐ¡ÅÖ
faster than 99.79% inÁì¿Û*/ 
int reverse(int x) {
    int res=0;
    while(x!=0){
        if(res>INT_MAX/10||res<INT_MIN/10)
            return 0;
        res=res*10+x%10;
        x=x/10;
    }
    return res;
}
