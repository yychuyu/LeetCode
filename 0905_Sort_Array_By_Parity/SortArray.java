/*
 * author: ace
 * time: 2018-11-16
 *
 * 主要思路: 利用一个和快排类似的原理来进行解答
 * 获取数组从左到右的一个奇数,然后再找到数组从右到左的一个偶数,两者再进行调换位置即可.注意进行越界的判断
 * */
public class SortArray {
    public int[] sortArrayByParity(int[] A) {
        int j = A.length - 1;
        for (int i = 0; i < j; i++) {
            if (A[i] % 2 == 1){
                while (A[j] % 2 == 1 && j > i) {
                    j--;
                }
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
        return A;
    }
}
