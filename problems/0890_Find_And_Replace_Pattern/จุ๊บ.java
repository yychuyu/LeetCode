class Solution {
    public static List<String> findAndReplacePattern(String[] words, String pattern)
    {
        List<String> list = new ArrayList<>();
        for(int i = 0; i < words.length; i++)
        {
            if(words[i].length() != pattern.length())
                continue;
            Map<Character,Character> hashMap = new HashMap<>();
            boolean isTest = true;
            for(int j = 0; j < pattern.length(); j++)
            {
                if(!hashMap.containsKey(pattern.charAt(j)))
                {
                    if(!hashMap.containsValue(words[i].charAt(j)))    //这种情况很容易遗漏，当某个字符从来没有在hashmap的key中出现过时，还要判断hashmap中的value是否出现将要插入的words[i].charat(j)的字符，如果有，那说明肯定和之前某个字符重复了，但这和pattern重复了
                        hashMap.put(pattern.charAt(j),words[i].charAt(j));
                    else
                    {
                        isTest = false;
                        break;
                    }
                }
                else
                {
                    if(hashMap.get(pattern.charAt(j)) != words[i].charAt(j))
                    {
                        isTest = false;
                        break;
                    }
                }
            }
            if(isTest == true)
                list.add(words[i]);
        }
        return list;
    }
}