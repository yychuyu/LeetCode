	Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
	n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
	Find two lines, which together with x-axis forms a container, such that the container contains the most water.
	
	Note: You may not slant the container and n is at least 2.

	Example:
		Input: [1,8,6,2,5,4,8,3,7]
		Output: 49
		
	题意理解：
		给定一个int型数组height，可以把数组放在坐标系中理解(x轴为下标，即0,1,2,3... y轴对应为为height[0]，height[1]，height[2]...)
		i,j为两个下标（假设i < j），把(i,0),(j,0),(j,height[j]),(i,height[i])这个梯形(可能是矩形)当成容器，求出它能装的水的最大体积
		
	我的代码(暴力)：
		
		class Solution {
			public int maxArea(int[] height) {
				 int max = 0;
					for(int i = 0;i <height.length-1;i ++){
						for(int j = i+1;j < height.length;j ++){
							if((j-i)*getMin(height[j],height[i])>max){
								max = (j-i)*getMin(height[j],height[i]);
							}
						}
					}
					return max;
			  }	

			 public static int getMin(int a,int b){
				  return (a<b)?a:b;
			 }
		}
	
	更好的解法：
		假设i=0,j=height.length-1,
			如果a[i] > a[j],即左侧高,此时高度以a[j]为准
				若i右移   则宽度减小  高度不会比原来大  总体积肯定不会比原来大
				若j左移   则宽度减小  高度可能比原来大	总体积可能比原来大
			如果a[i] < a[j],即左侧低,此时高度以a[i]为准
				若i右移   则宽度减小  高度可能比原来大  总体积可能比原来大	
				若j左移   则宽度减小  高度不会比原来大  总体积肯定不会比原来大
				
			综上，height[i]与height[j]中谁小谁就移动
			
			代码：
				public class Solution {
					public int maxArea(int[] height) {
						int maxarea = 0, l = 0, r = height.length - 1;
						while (l < r) {
							maxarea = Math.max(maxarea, Math.min(height[l], height[r]) * (r - l));
							if (height[l] < height[r])
								l++;
							else
								r--;
						}
						return maxarea;
					}
				}
			
				
				