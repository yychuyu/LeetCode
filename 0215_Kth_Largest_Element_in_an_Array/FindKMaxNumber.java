import java.util.Arrays;

public class FindKMaxNumber {
    public static void main(String[] argu) {
        int[] a = {9, 8, 7, 2, 3, 4, 1, 0, 6, 5};
        Arrays.sort(a);
        System.out.println(a[a.length - 2]);
    }
}

