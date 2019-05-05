void exchange(char* s1,int left,int right){
    while(left<right){
        char temp;
        temp=*(s1+left);
        *(s1+left)=*(s1+right);
        *(s1+right)=temp;
        left++;
        right--;
    }
}

char * reverseStr(char * s, int k){
    int len=0;
    while(*(s+len)){
        len++;
    }
    printf("len is %d\n",len);
    
    int left=0;
   int right=2*k;
    while(len>=right){
        exchange(s+left,0,k-1);        
        left+=2*k;
        right+=2*k;
    }
    int rest=len-left;
    if(rest>=k){
        exchange(s+left,0,k-1);
    }else{
        exchange(s+left,0,rest-1);
    }
    
    return s;
    

}