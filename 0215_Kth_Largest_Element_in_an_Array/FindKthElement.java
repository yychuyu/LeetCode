/**
 * * @ClassName Solution
 * * @Description 找寻数组中第K大的数
 * * @Author luoquan
 * * @Email luo.quan@aliyun.com
 * * WeChat luo_quan1982
 * * @Date 2018/11/16 9:47
 * * 解题思路
 * * 借助了快速排序的方法思想
 **/

public class FindKthElement {
    public static void main(String[] args) {
        int[] array = new int[]{3,2,3,1,2,4,5,5,6};
        FindKthElement f = new FindKthElement();
        int result = f.findKthLargest(array,4);
        System.out.println(result);
    }

    public int findKthLargest(int[] nums, int k) {
        int j = nums.length - k;
        //寻找第K大的数，反过来就是查找数组中length-k+1小的数
        return quickSort(nums, 0, nums.length - 1, j);
    }

    private int quickSort(int[] array, int left, int right, int k) {
        if (left <= right) {
            int mid = partition(array, left, right);
            if (k == mid)
                return array[mid];
            else if (k > mid)
                return quickSort(array, mid + 1, right, k);
            return quickSort(array, left, mid - 1, k);
        }
        return -1;
    }

    private int partition(int[] array, int left, int right) {
        int midIndex = midElement(array, left, right);

        if (midIndex != left) {
            int temp = array[left];
            array[left] = array[midIndex];
            array[midIndex] = temp;
        }

        int pivot = array[left];
        while (left < right) {
            while (left < right && array[right] >= pivot)
                right--;
            if (left < right)
                array[left++] = array[right];
            while (left < right && array[left] <= pivot)
                left++;
            if (left < right)
                array[right--] = array[left];
        }
        array[left] = pivot;
        return left;
    }

    //返回数组[left,mid,right]中中间的数的索引
    private int midElement(int[] array, int left, int right) {
        if (right - left <= 1)
            return left;
        int mid = (left + right) / 2;
        if (array[left] > array[mid] && array[left] > array[right])
            return array[mid] > array[right] ? mid : right;
        else if (array[mid] > array[left] && array[mid] > array[right])
            return array[left] > array[right] ? left : right;
        return array[left] > array[mid] ? left : mid;
    }
}