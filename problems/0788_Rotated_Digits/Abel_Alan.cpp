class Solution {
public:
    int rotatedDigits(int N) 
    {
        int count=0;
        int countpos;
        int countneg;
        int temp;
        int mod;
        for(int i=1;i<=N;i++)
        {
            countpos=0;
            countneg=0;
            temp=i;
            while(temp)
            {
                mod=temp%10;
                if(mod==4 || mod==7 || mod==3)
                {
                    break;
                }
                else
                {
                    if(mod==2 || mod==5 || mod==6 || mod==9)
                    {
                        countpos++;
                    }
                } 
                temp/=10;
            }
            if(temp==0 && countpos>0)
            {
                count++;
            }
        }
        return count;
    }
};
