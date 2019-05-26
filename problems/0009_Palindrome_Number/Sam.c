bool isPalindrome(int x) {
	int temp = x;
    int y = x;
    int i;
    int number = 0;
    if ( x < 0) 
    {
        return false;        
    }
    while ( temp  != 0 )//求取数值x的位数
    {
        number++;
        temp = temp / 10;
    }
    //求取后半部分翻转后的数值，1221的后半部分翻转是12,12321后半部分是12

     temp = 0;
     for ( i = 0; i < ( number / 2 ); i++ )
     {
         temp = temp * 10 + y % 10;
         y = y / 10;
     }
    //求取前半部分的值，1212的前半部分是12,12321的前半部分是12
    if ( number == 0 || number == 1)//数值为0或者是个位数
    {
        return true;
    }
    else if ( number % 2 != 0 )
    {
        number = (number/2)+1;
    }
    else 
    {
    	number = number / 2;
    }
    while ( number--)
    {
        y = x / 10;
        x = x / 10;
    }
    if ( y == temp )
    {
        return true;
    }
    else 
    {
        return false;        
    }
}
