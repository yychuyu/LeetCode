class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for (String str : cpdomains) {
            String[] s = str.split(" ");
            int value = Integer.valueOf(s[0]);
            String key = s[1];
            map.put(key, map.getOrDefault(key, 0) + value);
            while (key.contains(".")) {
                int index = key.indexOf(".");
                String substring = key.substring(index + 1);
                map.put(substring, map.getOrDefault(substring, 0) + value);
                key = substring;
            }
        }
        //
        //最后把集合转换为数组
        List<String> resultList = new ArrayList<>();
        Set<Map.Entry<String, Integer>> entriesResult = map.entrySet();
        for (Map.Entry<String, Integer> entry : entriesResult) {
            String item = entry.getValue() + " " + entry.getKey();
            resultList.add(item);
        }
        return resultList;
    }
}