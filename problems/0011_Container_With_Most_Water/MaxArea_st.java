package algorithm._011_maxArea;
/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
	图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例:
	输入: [1,8,6,2,5,4,8,3,7]
	输出: 49	
*/

public class MaxArea {
	public static void main(String[] args) {
		System.out.println(maxArea(new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 }));
	}

	//思路 : 要找最大的矩形面积,因为长越大,宽越大,矩形面积也就最大
	//		因此采用双指针的方法,从数组的头尾开始移动,此时一开始长即为最大,
	//		根据头尾指针所指向的值来决定矩形的宽,哪个值低则哪个值作为宽,
	//		后来移动值低的那个指针,保留值高的,这样才能确保后来矩形的宽会处于更高的值
	//解法 : 定义头尾指针以及存储最大面积和临时存放头尾指针所指向的值低的那个用来作为矩形宽
	//		30行实现了找头尾指针所指向的值中较低的那个值,
	//		31行实现了最大面积值的更新,若比当前比较的矩形面积大则不变
	public static int maxArea(int[] height) {
		int area = 0;
		int temp;
		int left = 0;
		int right = height.length - 1;
		while (left < right) {
			temp = height[left] < height[right] ? height[left] : height[right];
			area = area < (right - left) * temp ? (right - left) * temp : area;
			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return area;

		//暴力解法,没什么好说的
		/*int area = 0;
		int temp = 0;
		for (int i = 0; i < height.length; i++) {
			for (int j = i + 1; j < height.length; j++) {
				if (height[i] > height[j]) {
					temp = height[j];
				} else {
					temp = height[i];
				}
				if (area < temp * (j - i)) {
					area = temp * (j - i);
				}
			}
		}
		return area;*/
	}
}
