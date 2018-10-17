/*4ms，beat 100%*/
bool isUgly(int num) {
    if(1 == num)
        return true;
    if(0 == num)
        return false;
    if(0 > num)
        return false;
    int temp = num;
    int flag = 0;

    /*设置标识，0表明可以被该数整除*/
    int flag_2 = 0;
    int flag_3 = 0;
    int flag_5 = 0;
    while(1)
    {
        flag = 0;
        if(temp%2==0 && 0 == flag_2)
        {
           // printf("2 ok\n");
            temp = temp / 2;
        }   
        else
        {
            flag_2 =1;
            flag++;
        }
        if(temp%5 == 0 && 0 == flag_5)
        {
           // printf("5 ok\n");
            temp = temp / 5;
        }
        else
        {
            flag_5 =1;
            flag++;
        }
        if(temp %3 == 0 && 0 == flag_3)
        {
            //printf("3 ok\n");
            temp = temp/ 3;
        }
        else
        {
            flag_3 = 1;
            flag++;
        }
        /*如果三个都不能被除，或者最后结果为1，退出循环*/
        if(3 == flag || 1 == temp)
            break;
    }
    //printf("%d\n",temp);
    /*最后结果为1，则表明该数为丑数*/
    if(temp == 1)
    {
        //printf("true");
        return true;
    }
    else
    {
        return false;
    }
}
