class L_Solution {
    fun maxArea(height: IntArray): Int {
        var front:Int=0;
        var behind:Int=height.size-1;
        var water:Int=0;
        while (true){
            var area:Int=(behind-front)*Math.min(height[front],height[behind])
            water=Math.max(water,area);
            if (height[front]<=height[behind]){
                front++
            }else{
                behind--;
            }
            if(front>=behind){
                break
            }
        }
        return water;
    }
}