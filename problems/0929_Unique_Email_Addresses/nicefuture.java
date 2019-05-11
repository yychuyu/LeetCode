class Solution {
    public int numUniqueEmails(String[] emails) {
        HashSet<String> unique = new HashSet<>();
        for (String email : emails) {
            unique.add(this.returnString(email));
        }
        // Iterator iter = unique.iterator();
        // while (iter.hasNext()) {
        //     System.out.println(iter.next());
        // }
        return unique.size();
    }
    
    private String returnString(String email) {
        String result = email.replace(".", "");
        int plus = result.indexOf('+'), at0 = result.indexOf('@'), at1 = email.lastIndexOf('@');
        plus = plus == -1 ? at0 : plus;
        return result.substring(0, plus) + email.substring(at1);
    }
}
