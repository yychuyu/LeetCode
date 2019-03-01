import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Created by Json Wan on 2018/11/19.
 * Description：
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * The solution set must not contain duplicate triplets.
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 * 思路：问题定义为求a+b+c=v，首先nlog(n)排序，然后开始最外层遍历a，在后续数组中找b+c=v-a，转化为2Sum的问题（nlog(n)复杂度），总的复杂度为n2log(n)，后续再去重，提交时遇到特殊情况，数组为很多0，n2复杂度还是太高，因此先过滤一下首尾，将特别小的数与特别大的数都先排除，然后在第一层遍历中往后推移时过滤掉重复的数（可保证过滤后不会遗漏某些解），最后提交通过了，觉得n2log(n)应该是最优复杂度量级吧，只要能够提交通过，复杂度量级应该是同等量级的，只是其他的优化不同罢了，因为只要测试用例的长度足够，复杂度量级不同的解法应该是很容易被区分出来的，根本就不能通过。
 */
public class wanxu_pursue_0015 {

    public int binarySearch(int[] nums, int start, int end, int val) {
        int l = start;
        int r = end;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == val)
                return m;
            else if (nums[m] < val) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (nums[l] == val)
            return l;
        else
            return -1;
    }

    public List<List<Integer>> twoSum(int[] nums, int start, int end, int val) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for (int i = start; i < end; i++) {
            int index = binarySearch(nums, i + 1, end, val - nums[i]);
            if (index != -1) {
                List<Integer> list = new ArrayList<>();
                list.add(nums[i]);
                list.add(nums[index]);
                result.add(list);
            }
        }
        return result;
    }

    public List<List<Integer>> threeSum(int[] nums, int val) {
        //1.排序
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        //1.1初筛，将左边特别小的值去掉，将右边特别大的值去掉
        int start = 0;
        int end = nums.length - 1;
        boolean change = true;
        while (change) {
            change = false;
            while (start < end - 1 && nums[start] + nums[end - 1] + nums[end] < val) {
                change = true;
                start++;
            }
            while (start < end - 1 && nums[start] + nums[start + 1] + nums[end] > val) {
                change = true;
                end--;
            }
        }

        //2.遍历
        for (int i = start; i <= end; i++) {
            List<List<Integer>> subResult = twoSum(nums, i + 1, nums.length - 1, val - nums[i]);
            for (List<Integer> element : subResult) {
                List<Integer> list = new ArrayList<>();
                list.add(nums[i]);
                list.addAll(element);
                result.add(list);
            }
            int cur = nums[i];
            while (i < nums.length && nums[i] == cur)
                i++;
            i--;
        }
        //很多个0的输入表明先遍历再去重的方法是错误的
        //3.排序、去重
        result.sort(new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> o1, List<Integer> o2) {
                int i = 0;
                while (i < o1.size()) {
                    int e1 = o1.get(i);
                    int e2 = o2.get(i);
                    if (e1 != e2) {
                        return e1 - e2;
                    }
                    i++;
                }
                return 0;
            }
        });
        int i = 0;
        while (i < result.size() - 1) {
            List<Integer> curEle = result.get(i);
            List<Integer> nextEle = result.get(i + 1);
            boolean same = true;
            for (int j = 0; j < curEle.size(); j++) {
                if (!curEle.get(j).equals(nextEle.get(j))) {
                    same = false;
                    break;
                }
            }
            if (same) {
                result.remove(i);
            } else {
                i++;
            }
        }
        return result;
    }

    /**
     * 自己的解法，269ms，AC
     * @param nums
     * @return
     */
    public List<List<Integer>> threeSum(int[] nums) {
        return threeSum(nums, 0);
    }

    // O(N + logN) 最优解法27ms
    public static List<List<Integer>> bestThreeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();

        int len = nums.length;
        if (len < 3) {
            return res;
        }

        Arrays.sort(nums);
        int lastNeg = Arrays.binarySearch(nums, 0);
        int firstPos = lastNeg;
        int numZero;

        if (lastNeg < 0) {
            // no zeros, indices: [0..lastNeg,firstPos..N)
            numZero = 0;
            // retrieve insertion point from Java binarySearch
            lastNeg = ((-lastNeg) - 1) - 1;
            // firstPos is immediately after lastNeg
            firstPos = lastNeg + 1;
        } else {
            // zeros exist, indices: [0..lastNeg..zeros..firstPos..N)
            while (lastNeg > -1 && nums[lastNeg] == 0)
                lastNeg--;
            while (firstPos < len && nums[firstPos] == 0)
                firstPos++;
            numZero = firstPos - lastNeg - 1;
        }

        int min = nums[0];
        int max = nums[len - 1];
        // hash[i] = j means there are j instances of (i + min)
        int[] hash = new int[max - min + 1];
        for (int v : nums) {
            hash[v - min]++;
        }

        // Case 0: (0,0,0)
        if (numZero >= 3) {
            res.add(Arrays.asList(0, 0, 0));
        }

        // Case 1: (-X,0,X)
        if (numZero > 0) {
            for (int i = firstPos; i < len; i++) {
                // skip redundant values
                if (nums[i] == nums[i - 1]) {
                    continue;
                }

                int need = 0 - (nums[i] + min);
                if (need >= 0 && hash[need] > 0) {
                    res.add(Arrays.asList(0, nums[i], -nums[i]));
                }
            } // END for i
        }

        // Case 2: 1 positive, 2 negative
        for (int i = firstPos; i < len; i++) {
            // ignore repeated values
            if (i > firstPos && nums[i] == nums[i - 1]) {
                continue;
            }

            int half;
            if (nums[i] % 2 != 0) {
                // round up
                half = -(nums[i] + 1) / 2;
            } else {
                // Subcase: (x, -x/2, -x/2)
                half = -nums[i] / 2;
                if (half >= min && hash[half - min] > 1) {
                    res.add(Arrays.asList(nums[i], half, half));
                }
            }

            for (int j = lastNeg; j >= 0 && nums[j] > half; j--) {
                // Note: nums[j] > half prevents repeated cases. E.g., (4,-1,-3) and (4,-3,-1)
                // ignore repeated values
                if (j < lastNeg && nums[j] == nums[j + 1]) {
                    continue;
                }

                int need = 0 - (nums[i] + nums[j]);
                if (need >= min && hash[need - min] > 0)
                    res.add(Arrays.asList(nums[i], nums[j], need));
            } // END for j
        } // END for i

        // Case 3: 1 negative, 2 positive
        for (int i = lastNeg; i > -1; i--) {
            if (i < lastNeg && nums[i] == nums[i + 1]) {
                continue;
            }

            int half;
            if (nums[i] % 2 != 0) {
                half = -(nums[i] - 1) / 2;
            } else {
                half = -nums[i] / 2;
                // Subcase: (x, -x/2, -x/2), x < 0
                if (half - min < hash.length && hash[half - min] > 1)
                    res.add(Arrays.asList(nums[i], half, half));
            }

            for (int j = firstPos; j < len && nums[j] < half; j++) {
                if (j > firstPos && nums[j] == nums[j - 1]) {
                    continue;
                }

                int need = 0 - (nums[i] + nums[j]);
                if (need <= max && hash[need - min] > 0) {
                    res.add(Arrays.asList(nums[i], nums[j], need));
                }
            } // END for j
        } // END for i

        return res;
    }

    //44ms解法
    public List<List<Integer>> goodThreeSum(int[] nums) {
        int n = nums.length;
        int target = 0;
        List<List<Integer>> ret = new ArrayList<>();
        Arrays.sort(nums);

        for(int i = 0 ; i < n - 2 ; i++){
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            int t = -nums[i];
            while(left < right){
                if(nums[left] + nums[right] > t){
                    right--;
                }
                else if(nums[left] + nums[right] < t){
                    left++;
                }
                else{
                    List<Integer> push = new ArrayList<>();
                    ret.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
            }
        }

        return ret;
    }

    //48ms的最多人数的解法
    public List<List<Integer>> normalThreeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(nums.length < 3){
            return res;
        }else{
            Arrays.sort(nums);
            for(int i=0;i<nums.length-2;i++){
                if(nums[i]>0){
                    break;
                }
                if(i>0&&nums[i] == nums[i-1]){
                    continue;
                }
                int a1 = i + 1;
                int a2 = nums.length-1;
                int sum = 0;
                int com = 0;
                sum = 0 - nums[i];
                while(a1<a2){
                    com = nums[a1] + nums[a2];
                    if(com == sum){
                        res.add(new ArrayList<Integer>(Arrays.asList(nums[i],nums[a1],nums[a2])));
                        while(a1<a2 && nums[a1] == nums[a1+1]){
                            a1++;
                        }
                        while(a1<a2 && nums[a2] == nums[a2-1]){
                            a2--;
                        }
                        a1++;
                        a2--;
                    }else if(com < sum){
                        a1++;
                    }else{
                        a2--;
                    }
                }
            }
            return res;
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> result;
        result= new wanxu_pursue_0015().threeSum(new int[]{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6});
        result = new wanxu_pursue_0015().threeSum(new int[10000]);
        for (List<Integer> element :
                result) {
            for (Integer x :
                    element) {
                System.out.print(" " + x);
            }
            System.out.println();
        }
    }
}
