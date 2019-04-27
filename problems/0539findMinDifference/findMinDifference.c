int returnDifVal(int a,  int b)
{
    int temp1 = 0;
    int temp2 = 0;
    if (a > b)
    {
        temp1 = a - b;
    }
    else
    {
        temp1 = b - a; 
    }
    temp2 = 1440 - temp1;
    if (temp1 > temp2)
    {
        return temp2;
    }
    else
    {
        return temp1;
    }
}
int findMinDifference(char** timePoints, int timePointsSize) 
{
    int i = 0, j = 0;
    int return_value = 0;
    int temp = -1;
    int least_temp = 1440;
    int *arr = (int *)malloc(sizeof(int)*timePointsSize);
    //将字符串中的冒号：变成字符0,23:59->23059
    for (i=0; i<timePointsSize;i++)
    {
        *(timePoints[i]+2)='0';
        temp = atoi(timePoints[i]);
        arr[i] = (temp / 1000) * 60 + (temp % 100);
    }
    
    for (i=0; i<timePointsSize-1; i++)
    {
        for (j=i+1; j<timePointsSize; j++)
        {
            temp = returnDifVal(arr[i],arr[j]);
            if (temp < least_temp)
            {
                least_temp = temp;
            }
        }
    }
    return least_temp;
}