import java.util.*;

/**
 * * @ClassName FindAndReplace
 * * @Description TODO
 * * @Author luoquan
 * * @Email luo.quan@aliyun.com
 * * WeChat luo_quan1982
 * * @Date 2018/11/29 9:58
 **/

public class FindAndReplace {
    public List<String> findAndReplacePattern(String[] words, String pattern) {

        if (null == pattern || 0 == pattern.length())
            return null;

        List<String> list = new ArrayList<>();
        for (String word : words) {
            if (isMatch(word, pattern)) {
                list.add(word);
            }
        }

        return list;
    }

    private static boolean isMatch(String word, String pattern) {
        if (null == word || null == pattern || word.length() != pattern.length())
            return false;

        Map<Character, Character> map = new HashMap<>();
        for (int i = 0; i < word.length(); i++) {
            char key = pattern.charAt(i);
            if (map.containsKey(key) && map.get(key) != word.charAt(i))
                return false;
            else if (!map.containsKey(key) && map.containsValue(word.charAt(i)))
                return false;
            else
                map.put(key, word.charAt(i));
        }
        return true;
    }
}