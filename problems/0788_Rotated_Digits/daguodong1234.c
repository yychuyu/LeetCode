int judge_goodNumber(int num)
{
    bool cat1 = false;
    bool cat2 = false;
    do{
        int tmp = num%10;
        if(tmp==3||tmp==7||tmp==4)
        {
            return -1;
        }
        else if(tmp==2||tmp==5||tmp==6||tmp==9)
        {
            cat1 = true;
        }
        else
        {
            cat2 = true;
        }
    }while(num/=10);
    
    if(cat1)
        return 1;
    
    return -1;
}

int rotatedDigits(int N) {
    int  goodNumbers = 0;
    for(int i=1; i<=N; ++i)
    {
        if(judge_goodNumber(i)==1)
            ++goodNumbers; 
    }
    return goodNumbers;
}

