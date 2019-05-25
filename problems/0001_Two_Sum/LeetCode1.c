/*
Two SUm
两数之和
Note: The returned array must be malloced, assume caller calls free().
 
int* twoSum(int* nums, int numsSize, int target) {
    
}

知识：
C/C++中有一个快速排序的标准库函数 qsort ，在stdlib.h 中声明，其原型为：

void qsort(void *base, int nelem, unsigned int width, int ( * pfCompare)( const void *, const void *));

　　使用该函数，可以对任何类型的一维数组排序。该函数参数中，base 是待排序数组的起始地址，nelem 是待排序数组的元素个数，width 是待排序数组的每个元素的大小（以字节为单位），最后一个参数 pfCompare 是一个函数指针，它指向一个“比较函数”。排序就是一个不断比较并交换位置的过程。qsort 如何在连元素的类型是什么都不知道的情况下，比较两个元素并判断哪个应该在前呢？答案是，qsort 函数在执行期间，会通过pfCompare指针调用一个 “比较函数”，用以判断两个元素哪个更应该排在前面。这个“比较函数”不是C/C++的库函数，而是由使用qsort 的程序员编写的。在调用qsort 时, 将“比较函数”的名字作为实参传递给pfCompare。程序员当然清楚该按什么规则决定哪个元素应该在前，哪个元素应该在后，这个规则就体现在“比较函数”中。

qsort 函数的用法规定，“比较函数”的原型应是：int 函数名(const void * elem1, const void * elem2);该函数的两个参数，elem1 和elem2，指向待比较的两个元素。也就是说， * elem1 和* elem2 就是待比较的两个元素。该函数必须具有以下行为：

　　1) 如果 * elem1 应该排在 * elem2 前面，则函数返回值是负整数（任何负整数都行）。

　　2) 如果 * elem1 和* elem2 哪个排在前面都行，那么函数返回0

　　3) 如果 * elem1 应该排在 * elem2 后面，则函数返回值是正整数（任何正整数都行）。

*/
/*
思路：
1、创建一个结构体记录数组的值和对应的索引号
2、对objs中所有的val按照顺序排序
3、diff = target - objs[i].val；和objs[j].val比较
三种情况：
>  : i++
<  : j--
=  : 输出结果
*/
#include <stdio.h>
#include <stdlib.h>

struct object
{
    int val;
    int index;
};

static int compare(const void *a, const void *b)
{
    return ((struct object *)a) -> val - ((struct object *)b) -> val;
}

static int *twosum(int *nums, int numsSize, int target)
{
    int i,j;
    struct object *objs = malloc(numsSize * sizeof(*objs));//数据长度
    for(i = 0;i <numsSize; i++)
    {
        objs[i].val = nums[i];
        objs[i].index = i;//数组索引
    }
    qsort(objs,numsSize,sizeof(*objs),compare);
    int count = 0;
    int *results = malloc(2*sizeof(int));//分配两个int的值空间=result[2]
    i = 0;
    j = numsSize - 1;
    while(i < j)
    {
        int diff = target - objs[i].val;
        if(diff > objs[j].val)//当diff的值大于objs[j]时
        {
            while(++i < j && objs[i].val == objs[i-1].val){}// ”==“跳出while循环的条件，进入while(i < j)循环
        }
        else if(diff < objs[j].val)
        {
            while(--j > i && objs[j].val == objs[j+1].val){}
        }
        else 
        {
            //找到结果 diff = objs[j].val
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            return results;
        }
    }
    return NULL;
}

int main()
{
    int nums[] = {11,15,2,7};
    int target = 9;
    int count = sizeof(nums)/sizeof(*nums);
    int *index = twosum(nums,count,target);
    if(index != NULL)
    {
        printf("%d %d\n",index[0],index[1]);
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}
