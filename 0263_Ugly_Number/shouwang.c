
/*4ms*/
bool isUgly(int num) {
    if(1 == num)
        return true;
    if(0 >= num)
        return false;
    int temp = num;
    /*如果不能被2,3,5任何一个数整除，则非丑数，最后的结果为1，表明为丑数*/
    while(1 != temp)
    {
        if(temp % 2 == 0)
        {
 
            temp = temp / 2;
        }   
 
        else if(temp % 5 == 0)
        {

            temp = temp / 5;
        }
        else if(temp % 3 == 0)
        {
 
            temp = temp / 3;
        }
        else
        {
            return false;
        }
    }
    return true;
