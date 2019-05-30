class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> cnt = new HashMap<>();
        for (int i : nums) {
            if (cnt.containsKey(i)) return true;
            else cnt.put(i, 1);
        }
        return false;
    }
}

/*
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> cnt = new HashMap<>();
        for (int i : nums) {
            if (!cnt.containsKey(i)) cnt.put(i, 1);
            else {
                int old = cnt.get(i);
                cnt.put(i, old+1);
            }
        }
        Iterator iter = cnt.values().iterator();
        while (iter.hasNext()) {
            // System.out.print(iter.next() + " ");
            if ((int)iter.next() > 1) return true;
        }
        return false;
    }
}*/
