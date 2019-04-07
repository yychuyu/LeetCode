
int hammingDistance(int x,int y)
{
    int result = 0;
    /*get the temp result*/
    int temp = x^y;
    /*calc the 1 of temp result*/
    while (temp != 0)
    {
        if (temp % 2 == 1)
        {
            result++;
        }
        temp = temp >>1;
    }
   return result;
}
