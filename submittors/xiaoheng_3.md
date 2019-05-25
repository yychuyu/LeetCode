# 盛最多水的容器(中等)

**skills: 动态规划，双指针**



## 题目

>给定 *n* 个非负整数 *a*1，*a*2，...，*a*n，每个数代表坐标中的一个点 (*i*, *a**i*) 。在坐标内画 *n* 条垂直线，垂直线 *i* 的两个端点分别为 (*i*, *a**i*) 和 (*i*, 0)。找出其中的两条线，使得它们与 *x* 轴共同构成的容器可以容纳最多的水。

> **说明：**你不能倾斜容器，且 *n* 的值至少为 2。



![](https://uploader.shimo.im/f/cnhA3gxtlZACtFP1.jpg!thumbnail)



**示例:**

>**输入:** [1,8,6,2,5,4,8,3,7]

> **输出:** 49



## 思路

利用动态规划，创建一个9*9的二维数组，如下图，（x,y）存储的是，x到y范围内的最大面积。灰色是初始化时填充的，不用管也用不到，填充顺序按照 红橙黄绿青 填充，填充 (0,1) 时选取 （0,0）和（1,1）和 area（0,1）中的最大值，area是求0和1组成的面积，以此类推（0,4）就是我们需要的。

![](https://uploader.shimo.im/f/tcHexo7y7j0zfsTY.jpg!thumbnail)



## c++代码（动态规划）

```c 
class Solution {
public:
    
    int area(vector<int>& in,int left,int right){
        int area = min(in[left],in[right]) * (right-left);
        return area;
    }
    
    int maxArea(vector<int>& height) {
        
        int length = height.size();
          
        //这个是动态创建指定长度二维数组
        //int ** list; 
        //list = new int *[length+1]; 
        //for(int i = 0; i < length+1; i ++) 
        //list[i] = new int[length+1];

        //静态创建list数组
        int list[1000][1000] = {0}; 
 	
        for(int x = 1;x < length;++x){
            for(int y = 0;y + x < length; ++y){
                list[y][x+y] = max(max(list[y][x+y-1],list[y+1][x+y]),area(height,y,x+y));
            }
        }
        
        return list[0][length-1];
    }
};
```

至此，证毕。事实证明算法思想没问题，也能求出来正确解。

**但是，系统不给通过，系统测试用例给了5000长的数组，不管是动态创建还是静态创建二维数组，都会栈溢出。**



## c++代码（双指针）

>这种方法背后的思路在于，两线段之间形成的区域总是会受到其中较短那条长度的限制。此外，两线段距离越远，得到的面积就越大。

> 我们在由线段长度构成的数组中使用两个指针，一个放在开始，一个置于末尾。 此外，我们会使用变量 maxarea

> *maxarea* 来持续存储到目前为止所获得的最大面积。 在每一步中，我们会找出指针所指向的两条线段形成的区域，更新 maxarea

> *maxarea*，并将指向较短线段的指针向较长线段那端移动一步。



> 最初我们考虑由最外围两条线段构成的区域。现在，为了使面积最大化，我们需要考虑更长的两条线段之间的区域。如果我们试图将指向较长线段的指针向内侧移动，矩形区域的面积将受限于较短的线段而不会获得任何增加。但是，在同样的条件下，移动指向较短线段的指针尽管造成了矩形宽度的减小，但却可能会有助于面积的增大。因为移动较短线段的指针会得到一条相对较长的线段，这可以克服由宽度减小而引起的面积减小。



```c
class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int left = 0;  //左指针
        int right = height.size()-1;  //右指针
        int maxarea = 0;
        
        while(left != right){
            maxarea = max(min(height[left],height[right]) * (right-left) , maxarea);
            
            (height[left] < height[right]) ? ++left : --right;
            
        }
        return maxarea;
    }
};
```

