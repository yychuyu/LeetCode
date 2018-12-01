/**
 * * @ClassName RemoveDupLuoQuan
 * * @Description TODO
 * * @Author luoquan
 * * @Email luo.quan@aliyun.com
 * * WeChat luo_quan1982
 * * @Date 2018/11/22 9:25
 **/

public class RemoveDupLuoQuan {
    public int removeDuplicates(int[] nums) {
        if (null == nums || 0 == nums.length)
            return 0;
        else if (1 == nums.length)
            return 1;
        int size = 1;
        int noRepetIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[noRepetIndex]) {
                size++;
                noRepetIndex++;
                nums[noRepetIndex] = nums[i];
            }
        }
        return size;
    }
}
