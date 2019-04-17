int cmp(int a,int b){
    if(a > b)
        return 1;
    else if(a < b)
        return -1;
    else
        return 0;
}
int maxTurbulenceSize(int* A, int ASize) {
    int i,n,max;
    n = 0;
    i = 1;
    max = 1;
    if(ASize == 1)
        return 1;
    else
    {
    for(i=1;i<ASize-1;i++)
    {
        if(cmp(A[i],A[i-1])*cmp(A[i],A[i+1]) <= 0.0)
        {
            if((A[i]-A[i-1]))
                max = max > (i - n + 1) ? max : (i - n + 1);
            n = i;
        }
    }
    if((A[i]-A[i-1]))
        max = max > (i - n + 1) ? max : (i - n + 1);
    
    return max;
    }
}