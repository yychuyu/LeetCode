class Solution {
    public int maxArea(int[] height) {
        if (height == null || height.length < 2)
            return 0;
        
        int left = 0;
        int right = height.length - 1;
        int max = 0;

        while (left < right) {
            int t = Math.min(height[left], height[right]) * (right - left);
            max = max > t ? max : t;
            if (height[left] > height[right])
                right--;
            else left++; 
        }

        return max;
    }
}