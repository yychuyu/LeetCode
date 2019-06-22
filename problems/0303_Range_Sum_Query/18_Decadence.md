## 题目描述
```text
Leetcode 303
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

说明:
1、你可以假设数组不可变。
2、会多次调用 sumRange 方法。
```
## 解题思路
```text
给定一个整数序列，求指定子序列和。
提示：数组不会发生变化；大量sumRange函数调用。
题目本身非常简单，只需要遍历 ii 到 jj ，累计得到和即可。但是，这样是TLE的，所给提示也就没有意义了。
所以，题目考察的是效能，换一个方向思考，我们可以存储子序列和，每个下标处的值为[0,i][0,i]的所有元素和;
那么[i,j][i,j]子序列和 =sum[j]−sum[i−1]=sum[j]−sum[i−1]；
注意，i==0i==0时，直接返回sum[j]sum[j]即可。
```
## 代码实现
```java

class NumArray { 
    static int[] sumArray ;
    static int[] array;
    public NumArray(int[] nums) {
        sumArray = new int[nums.length];
        array = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            array[i] = nums[i];
            if (i == 0) sumArray[i] = nums[i];
            else sumArray[i] = nums[i] + sumArray[i-1];
        }
    }
    public int sumRange(int i, int j) {
        return  sumArray[j] - sumArray[i] + array[i];
    }
}

```
