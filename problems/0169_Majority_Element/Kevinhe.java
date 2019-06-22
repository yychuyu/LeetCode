import java.util.HashMap;
import java.util.Hashtable;

public class Main {

    public static void main(String[] args) {
        System.out.println(majorityElement(new int[]{3,2,3}));
    }
    public static int majorityElement(int[] nums) {
        int count = 1;
        int nownumber = nums[0];
        for(int i = 1;i<nums.length;i++){
            if(count==0){
                nownumber = nums[i];
                count++;
            }else if(nums[i]!=nownumber){
                count--;
            }else if(nums[i] == nownumber){
                count++;
            }
        }
        return nownumber;
    }

//    public static int majorityElement(int[] nums) {
//        HashMap<Integer, Integer> hashmap = new HashMap<>();
//        for (int i = 0; i < nums.length; i++) {
//            if (!hashmap.containsKey(nums[i])) {
//                hashmap.put(nums[i], 1);
//            } else {
//                int value = hashmap.get(nums[i]);
//                hashmap.put(nums[i], ++value);
//            }
//        }
//        for (int key : hashmap.keySet()){
//            int cmp = (nums.length%2==0)?nums.length/2:nums.length/2+1;
//            if(hashmap.get(key)>=cmp)
//               return key;
//        }
//        return 0;
//    }
}
