package leetcodePart5;

/**
 * @author 刘云生
 * @date 2019/4/917:31
 */
public class NO27_liuyunsheng {
    public static void main(String[] args) {
        System.out.println(NO27_liuyunsheng.removeElement(new int[]{1, 2, 1, 2, 2, 3, 2, 5, 2},2));
    }
    public static int removeElement(int[] nums,int val){
        //仍然是参考快慢指针的设计思想
        if (nums.length==0){
            return 0;
        }else {
            int num=0;
            for (int i = 0; i <nums.length ; i++) {
                if (nums[i]!=val){
                    nums[num]=nums[i];
                    num++;
                }
            }
            return num;
        }
    }

}
