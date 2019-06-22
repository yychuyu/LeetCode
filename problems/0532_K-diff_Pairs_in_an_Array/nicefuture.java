// Runtime: 10 ms
// Memory Usage: 40.1 MB
class Solution {
    public int findPairs(int[] nums, int k) {
        
        if (k < 0) return 0;  // Attention: This line make runtime from 19ms to 10ms ...
        
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int num: nums) {
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        
        int cnt = 0;
        for (Map.Entry<Integer, Integer> pair : map.entrySet()) {
            int key = pair.getKey();
            int value = pair.getValue();
            if (k == 0 && value > 1) {
                pair.setValue(value-1);
                cnt++;
            } else if (k > 0) {
                if (map.containsKey(key+k)) cnt++;
            }
        }
        return cnt;
    }
}
