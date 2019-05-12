class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet();
        Set<Integer> set2 = new HashSet();
        for(int num : nums1){
            set1.add(num);
        }
        for(int num : nums2){
            if(set1.contains(num)){
                set2.add(num);
            }
        }
        int[] result = new int[set2.size()];
        int index = 0;
        for(int num : set2){
            result[index] = num;
            index++;
        }
        return result;
    }
}