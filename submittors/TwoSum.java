import java.util.HashMap;
import java.util.Map;

/**
 * @author lonecloud
 * @version v1.0
 * @Package PACKAGE_NAME
 * @Description: TODO
 * @date 2019/3/2上午12:52
 */
public class TwoSum {
    /**
     * 简单原理
     *   时间复杂度 ：O(n*n)
     *  1. 遍历数组获取值以第一个数为加数，第二个数为被加数进行求和和目标做对比
     *  2. 如果匹配成功,则返回结果，否则则失败!
     * @param nums
     * @param target
     * @return
     */
    public  int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i]+nums[j]==target) {
                    return new int[] { i, j };
                }
            }
        }
        throw new IllegalArgumentException("没有找到问题答案！");
    }

    /**
     * 时间复杂度:O(n)
     * 第二种方法，使用空间换取时间来做
     * 1. 创建Map数据对象存储该数据
     * 2. 键存储的为差值，值存储为下标
     * 3. for循环判断，如果key中包含则说明这两个值相等直接返回，否则将差值插入进去
     * @param nums
     * @param target
     * @return
     */
    public int[] twoSum2(int[] nums,int target){
        Map<Integer,Integer> refix=new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int len = target - nums[i];
            if (refix.containsKey(len)){
                return new int[]{i,refix.get(len)};
            }
            refix.put(len,i);
        }
        throw new IllegalArgumentException("没有找到问题答案！");
    }
}
