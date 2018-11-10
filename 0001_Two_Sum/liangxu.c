

  4 int* twosum(int*nums, int numssize, int target)
  5 {
  6     int i = 0;
  7     int j = 0;
  8     static int  result[2];
  9     for(i = 0; i < numsize; i++)
 10     {
 11         for(j = i+1; j < numsize; j++ )
 12         {
 13             if(nums[i]+nums[j]==target)
 14             {
 15                 result[0] = i;
 16                 result[1] = j;
 17             }
 18         }
 19     }
 20     return result;
 21 }

