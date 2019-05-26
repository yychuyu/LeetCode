public class Solution {
    /*
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    class Pair {
        Integer value;
        Integer index;

        Pair(Integer value, Integer index) {
            this.value = value;
            this.index = index;
        }
        Integer getValue() {
            return this.value;
        }
    }

    class ValueComparator implements Comparator<Pair> {

        @Override
        public int compare(Pair o1, Pair o2) {
            return o1.getValue().compareTo(o2.getValue());
        }
    }
    public int[] twoSum(int[] numbers, int target) {
        // write your code here
        //用一个pair数组记录每个numbers[i]的值和它的位置i，防止排序后不知道该元素的位置
        Pair[] number = new Pair[numbers.length];
        for(int i=0;i<numbers.length;i++) {
            number[i] = new Pair(numbers[i], i);
        }
        //排序后使用双指针
        Arrays.sort(number, new ValueComparator());
        int L=0, R =  numbers.length-1;
        while(L<R) {
            if( number[L].getValue() + number[R].getValue() == target) {
                int t1 = number[L].index;
                int t2 = number[R].index;
                int[] result = {Math.min(t1,t2), Math.max(t1,t2)};
                return result;
            }
            if( number[L].getValue() + number[R].getValue() < target) {
                L++;
            } else {
                R--;
            }
        }
        int[] res = {};
        return res;
    }
}