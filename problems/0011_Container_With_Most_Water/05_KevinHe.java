public class question10 {
    public static void main(String[] args) {

    }
//    public int maxArea(int[] height) {
//        int MAX = Integer.MIN_VALUE;
//        for(int i = 0;i<height.length-1;i++){
//            for(int j = i+1;j<height.length;j++){
//                int square = (j-i) *(height[j]>height[i]?height[i]:height[j]);
//                if(square > MAX) MAX = square;
//            }
//        }
//        return MAX;
//    }

    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length-1;
        int result = Integer.MIN_VALUE;
        while(left<right){
            int square = Math.min(height[left],height[right])*(right -left) ;
            result = square>result?square:result;
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return result;
    }
}
