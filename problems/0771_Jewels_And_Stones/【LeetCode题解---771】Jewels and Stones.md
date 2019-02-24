## 【LeetCode题解---771】Jewels and Stones 

### 题目 

> You're given strings `J` representing the types of stones that are jewels, and `S` representing the stones you have.  Each character in `S` is a type of stone you have.  You want to know how many of the stones you have are also jewels.
>
> The letters in `J` are guaranteed distinct, and all characters in `J` and `S` are letters. Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.
>
> Example 1:
>
> ```
> Input: J = "aA", S = "aAAbbbb"Output: 3
> ```
>
> Example 2:
>
> ```
> Input: J = "z", S = "ZZ"Output: 0
> ```
>
> Note:
>
> - `S` and `J` will consist of letters and have length at most 50.
> - The characters in `J` are distinct.

### 词汇

* `representing `代表
* `jewels` 珠宝
* `stones` 石头
* `guaranteed` 保证    

### 翻译

​	给定字符串J和S，求S中在J中出现的字符总数。

   	 注意，区分大小写即a和A不一样。

### 解法

#### 解法一

\* 使用Hash方法

\* 通过遍历字符串S和J，两两进行比较，判断stone中有多少颗jewel。

\* 时间复杂度为O(s * j)。(s为字符串S的长度，j为字符串J的长度)。

\* 空间复杂度为O(1)。

```java

```

#### 解法二

 \*  暴力解法

 \*  时间复杂度：O（n^2）                            

 \*  空间复杂度：O（1)

```java

```



>  以上代码会同步更新在本人的Github和CSDN上
>
> Github地址：https://github.com/Bylant/LeetCode
>
> CSDN地址：https://blog.csdn.net/ZBylant

