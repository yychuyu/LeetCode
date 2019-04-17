




bool isPalindrome(int x) {
    int n,i;
    int stack[100];
    int temp = x;
    
    //小于零一定不是回文
    if (x < 0)
    {
        return false;
    }
    //大于零小于10一定是回文
    else if(x >= 0 && x < 10)
    {
        return true;
    }
    else
    {
        n = 0;
        while (x >= 10)
        {
            stack[n] = x % 10;
            x = x / 10;
            n++;
        }
        stack[n] = x;
        for (i=n-1; i>=0; i--)
        {
            x += pow(10,n-i) * stack[i];
        }
        if (temp == x)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}
