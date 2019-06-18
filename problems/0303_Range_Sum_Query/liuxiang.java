class NumArray {
   //定义一个sum数组用来存储左边的和，例如sum[2]表示nums[0]+nums[1]
   //很容易可以得出sum[i]=sum[i-1]+nums[i-1];
    
    int[] sum;

    public NumArray(int[] nums) {
        int n=nums.length;
        sum=new int[n+1];
        sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
    }
    
    public int sumRange(int i, int j) {
          return sum[j+1]-sum[i];  
        
    }
}

