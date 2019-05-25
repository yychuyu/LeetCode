class Solution {
    public String[] reorderLogFiles(String[] logs) {
        ArrayList<String> num = new ArrayList<>();
        LinkedList<String> alp = new LinkedList<>();
        for (String log : logs) {
            String real = log.substring(log.indexOf(' ')+1);
            if (real.charAt(0) >= '0' && real.charAt(0) <= '9') {
                num.add(log);
            } else {
                this.insert(alp, log);
            }
        }
        for (String item : num) {
            alp.add(item);
        }
        return (String[])alp.toArray(new String[0]);
    }
    
    private void insert(LinkedList<String> alp, String log) {
        // insert into LinkedList with order
        String real = log.substring(log.indexOf(' ')+1);
        for (int i=0; i<alp.size(); i++) {
            if (real.compareTo(alp.get(i).substring(alp.get(i).indexOf(' ')+1)) <= 0) {  
                alp.add(i, log);
                return;
            }
        }
        alp.add(log);
    }
}
