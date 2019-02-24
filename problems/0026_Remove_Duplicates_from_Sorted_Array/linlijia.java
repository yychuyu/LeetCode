class Solution {
      public int removeDuplicates(int[] nums) {
          
          if (nums == null || nums.length == 0) {
              return 0;
          }
          if (nums.length == 1) {
              return 1;
          }
          
          // 标记不重复元素的个数
          int cnt = 1;
          for (int i = 1; i < nums.length; i++) {
              if (nums[i] != nums[i - 1]) {
                  nums[cnt] = nums[i];
                  cnt++;
              }
          }
          
          return cnt;
          
      }
  }