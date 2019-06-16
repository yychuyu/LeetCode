int repeatedNTimes(int* A, int ASize) {
    int i,j,temp;
    for(i=0;i<ASize-1;i++){
        for(j=i+1;j<ASize;j++){
            if(A[i]>A[j]){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
   if(A[(ASize-1)/2]==A[(ASize-1)/2-1]){
       return A[(ASize-1)/2];
   }else{
       return A[ASize/2];
   }
}