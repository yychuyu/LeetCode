 public static int[][] matrixReshape(int[][] nums, int r, int c) {
	   if(r*c!=nums.length*nums[0].length)return nums;
	   
	   int[][] result=new int[r][c];
	   List<Integer> list=new ArrayList<>();
	   
	   for(int i=0;i<nums.length;i++) {
		   for(int j=0;j<nums[0].length;j++) {
			   list.add(nums[i][j]);
		   }
	   }
	   System.out.println(list.size());
	   int k=0;
	   for(int i=0;i<r;i++) {
		   for(int j=0;j<c;j++) {
			   result[i][j]=list.get(k);
			   k++;
		   }
	   }
	   System.out.println(k);
	   return result;
	}
