/**
 * Author: Json Wan
 * Created at: 2019/1/28 14:47
 * Description:
 * 11. Container With Most Water
 Medium
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 Note: You may not slant the container and n is at least 2.
 The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
  Example:
 Input: [1,8,6,2,5,4,8,3,7]
 Output: 49
 思路：最简单的思路是Cn2遍历，算出每一种情况下的装水的值，找出最大的即可。
 最优的解法应该得考虑动态规划。//用不着。。
 **/
public class wanxu_pursue_0011 {

    public int bestMaxArea(int[] height) {
        int left = 0,maxWater = 0;
        int right = height.length-1;
        while(left < right){
            int high = Math.min(height[left], height[right]);
            int currentWater = high * (right - left);

            if(currentWater > maxWater) maxWater = currentWater;

            //从左右两侧出发，分别依次向中间推进，把不可能的柱子逐渐排除在外
            //如果左边柱子的右边一个比左边的还低，那一定不会用上它，只有更高的柱子才有可能装得比左边多
            while(height[left] <= high && left < right) left++;
            //右边同理
            while(height[right] <= high && left < right) right--;
        }
        return maxWater;
    }

    //AC,12.75%
    public int calc(int[] height,int start,int end){
        int minValue=height[start]<height[end]?height[start]:height[end];
        return minValue*(end-start);
    }

    public int maxArea(int[] height) {
        int maxVolume=0;
        for(int i=0;i<height.length-1;i++){
            for(int j=i+1;j<height.length;j++){
                int volume=calc(height,i,j);
                if(volume>maxVolume){
                    maxVolume=volume;
                }
            }
        }
        return maxVolume;
    }

    public static void main(String[] args) {
        wanxu_pursue_0011 instance=new wanxu_pursue_0011();
        //边界测试
        System.out.println(instance.maxArea(new int[]{})==0);
        //常规测试
        System.out.println(instance.maxArea(new int[]{1,8,6,2,5,4,8,3,7})==49);
        //复杂度测试
        System.out.println(instance.maxArea(new int[]{1,8,6,2,5,4,8,3,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0})==49);

    }
}
