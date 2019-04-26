class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        HashMap<String, Integer> cnt = new HashMap<>();
        paragraph = paragraph.toLowerCase();  // 转换成小写

        int front=0;
        for (int i=0; i<paragraph.length(); i++) {  // 单词计数
            char c = paragraph.charAt(i);
            if (front != -1 && !((c>='a'&&c<='z') || (c>='A'&&c<='Z'))) {
                String s = paragraph.substring(front, i);
                // System.out.print(s+"|");
                int old = cnt.getOrDefault(s, 0);
                cnt.put(s, old+1);
                front = -1;
            } else if (front == -1 && ((c>='a'&&c<='z') || (c>='A'&&c<='Z'))) {
                front = i;
            }
        }
        if (front != -1) {
            String s = paragraph.substring(front, paragraph.length());
            // System.out.print(s+"|");
            int old = cnt.getOrDefault(s, 0);
            cnt.put(s, old+1);
        }
        
        for (String ban : banned) {  // 清除禁用词
            cnt.remove(ban);
        }
        
        String key = "";
        int value = 0;
        Iterator<String> keys = cnt.keySet().iterator();
        while (keys.hasNext()) {  // 找最大值
            String k = keys.next();
            int v = cnt.get(k);
            // System.out.print(k+":"+v+" ");
            if (v > value) {
                key = k;
                value = v;
            }
        }
        
        return key;
    }
}
