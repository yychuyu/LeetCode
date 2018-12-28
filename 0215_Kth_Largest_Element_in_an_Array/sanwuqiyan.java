class Solution {
	    public int findKthLargest(int[] nums, int k) {
	        int len = nums.length;
	        if( len==0 ) return 0;
	        int i=0, j=len-1;
	        int tl=i, th=j, pivot, m=len-k;
	        while( true ) {
	        	pivot = nums[i];
	        	while( i<j ){
	        		while( i<j && nums[j]>=pivot ) j--;
	        		nums[i] = nums[j];
	        		while( i<j && nums[i]<=pivot ) i++;
	        		nums[j] = nums[i];
	        	}
	        	nums[i] = pivot;
	        	if( i==m ) return nums[i];
	        	else if( i<m ) {
	        		tl = ++i;
	        		j = th;
	        	}else {
	        		th = --j;
	        		i = tl;
	        	}
	        }
 
	    }
	}
