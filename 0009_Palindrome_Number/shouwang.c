bool isPalindrome(int x) {
    if(x < 0)
        return false;
    /*int最大有10位*/
    char bit[10] = {0};
    int temp = x;
    int loop = 0;
    int pos = 0;
    /*将每位存储*/
    for(loop = 0;0 != temp;loop++ )
    {
        pos = temp % 10;
        temp = temp /10;
        bit[loop] = pos;
    }
    int num = loop;
    /*判断折半各位是否相等*/
    for(loop = 0;loop < num/2;loop++)
    {
        if(bit[loop] != bit[num-loop-1])
            return false;
    }
    return true;   
}
