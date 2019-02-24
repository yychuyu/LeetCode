/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if(NULL == digits)
        return NULL;
    int loop = 0;
    int *ret = NULL;
    /*按照普通加法计算，9+1进1，当前位置0*/
    for(loop = digitsSize-1; loop >= 0;loop--)
    {
        if(9 != digits[loop] )
        {
            /*当前不等于9，加1后退出即可*/
            digits[loop]+=1;
            break;
        }
        else
        {
            /*等于9时，进位，当前位置0*/
            digits[loop] = 0;
        }
    }
    /*没有循环到最后，说明结果位数不变*/
    if(0 <= loop)
    {
        /*这里直接返回原数组，是否不太好？*/
        *returnSize = digitsSize;
        return digits;
    }
    else
    {
        /*全为9，需要增加一位*/
        ret = (int*)calloc(digitsSize +1 ,sizeof(int));
        if(NULL == ret)
        {
            return NULL;
        }
        ret[0] = 1;
        *returnSize = digitsSize +1;
        return ret;
    }
}
