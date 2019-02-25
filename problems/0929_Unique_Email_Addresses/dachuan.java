class Solution {
    public int numUniqueEmails(String[] emails) {
        Set sets = new HashSet();
        for (String email : emails) {
            String[] strs = email.split("@");
            String left = strs[0];
            left = left.replace(".", "");
            int index = left.indexOf("+");
            left = left.substring(0, index);

            String right = strs[1];
            String content = left + right;
            sets.add(content);
        }
        return sets.size();
    }
}