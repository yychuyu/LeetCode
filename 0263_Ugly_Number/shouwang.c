bool isUgly(int num) {
    if(1 == num)
        return true;
    if(0==num)
        return false;
    if(0 >num)
        return false;
    int temp = num;
    int flag = 0;
    int flag_2 = 0;
    int flag_3 = 0;
    int flag_5 = 0;
    while(1)
    {
        flag = 0;
        if(temp%2==0 && 0 == flag_2)
        {
           // printf("2 ok\n");
            temp = temp /2;
        }   
        else
        {
            flag_2 =1;
            flag++;
        }
        if(temp%5 == 0 && 0 == flag_5)
        {
           // printf("5 ok\n");
            temp = temp /5;
        }
        else
        {
            flag_5 =1;
            flag++;
        }
        if(temp %3 == 0 && 0 == flag_3)
        {
            //printf("3 ok\n");
            temp =temp/3;
        }
        else
        {
            flag_3 = 1;
            flag++;
        }
        if(3 == flag || 1 == temp)
            break;
    }
    //printf("%d\n",temp);
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
