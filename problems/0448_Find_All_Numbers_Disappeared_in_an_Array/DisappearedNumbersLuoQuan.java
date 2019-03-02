import java.util.ArrayList;
import java.util.List;

/**
 * @Author luoquan
 * @Email 37629327@qq.com luo.quan@aliyun.com
 * @Description
 * @Date 2019/3/2 15:31
 */
public class DisappearedNumbersLuoQuan {

    public static List<Integer> findDisappearedNumbers(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            //如果位置上的索引与数值一致则直接跳过
            if (nums[i] == i + 1)
                continue;
            int index = Math.abs(nums[i]) - 1;
            nums[index] = Math.abs(nums[index]) * -1;
        }

        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0)
                result.add(i + 1);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] array = new int[]{4,3,2,7,8,2,3,1};
        System.out.println(findDisappearedNumbers(array));
    }

}
