/**
 * @Author luoquan
 * @Email 37629327@qq.com luo.quan@aliyun.com
 * @Description
 * @Date 2019/3/9 11:50
 */
public class FindFistAndLast {

    public int[] searchRange(int[] nums, int target) {

        if (null == nums || 0 == nums.length)
            return new int[]{-1, -1};

        int length = nums.length;
        int index = searchIndex(nums, 0, nums.length - 1, target);
        int leftIndex;
        int rightIndex;
        int result;

        if (index < 0)
            return new int[]{-1, -1};

        leftIndex = index;
        rightIndex = index;

        while (leftIndex > 0) {
            result = searchIndex(nums, 0, leftIndex - 1, target);
            if (result > -1)
                leftIndex = result;
            else
                break;
        }

        while (rightIndex < length - 1) {
            result = searchIndex(nums, rightIndex + 1, length, target);
            if (result > -1)
                rightIndex = result;
            else
                break;
        }

        return new int[]{leftIndex, rightIndex};

    }

    private static int searchIndex(int[] arr, int left, int right, int target) {
        if (left <= right) {
            int middle = (left + right) / 2;
            if (target == arr[middle])
                return middle;
            else if (target > arr[middle])
                return searchIndex(arr, middle + 1, right, target);
            else
                return searchIndex(arr, left, middle - 1, target);
        }
        return -1;
    }
}
