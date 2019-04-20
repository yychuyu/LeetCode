package leetcodePart5;

/**
 * @author 刘云生
 * @date 2019/4/917:31
 */
public class NO26_liuyunsheng {
    public static void main(String[] args) {
        System.out.println(NO26_liuyunsheng.remove(new int[]{1, 1, 2, 3, 3, 3, 4, 4, 4, 5}));
    }
    public static int remove(int[] nums){
        //快慢指针
        if (nums.length==0) {
            return 0;
        }else {
            int i=0;
            for (int j = 1; j <nums.length ; j++) {
                if (nums[i]!=nums[j]){
                    i++;
                    nums[i]=nums[j];
                }
            }
            return i+1;
        }
    }
}
