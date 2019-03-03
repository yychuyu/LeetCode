/**
 * @author lonecloud
 * @version v1.0
 * @Package PACKAGE_NAME
 * @Description: TODO
 * @date 2019/3/2上午12:52
 */
public class MainTest {


    public static void main(String[] args) {
        TwoSum twoSum=new TwoSum();
        int[] sums=new int[]{1,2,4,1};
        int target=6;
        int[] results = twoSum.twoSum(sums, target);
        int[] results2 = twoSum.twoSum(sums, target);
        System.out.println(results[0]+"-"+results[1]);
        System.out.println(results2[0]+"-"+results2[1]);
    }
}