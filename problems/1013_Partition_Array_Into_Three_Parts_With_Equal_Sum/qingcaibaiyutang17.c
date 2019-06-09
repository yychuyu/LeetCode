bool canThreePartsEqualSum(int* A, int ASize){
    int i,sum=0,m=0,j=0;
    for(i=0;i<ASize;i++){
        sum+=A[i];
    }
    if(sum%3!=0)return false;
    for(i=0;i<ASize;i++){
        m+=A[i];
        if(m==(sum/3)){
            ++j;
            m=0;
        }
    }
    return (j==3);
}