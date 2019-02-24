import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @Author 宋宗垚
 * @Date 2018/11/30 20:25
 * @Description TODO
 */
/*
你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。



示例：

输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
输出：["mee","aqq"]
解释：
"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。
 */
public class FindandReplacePattern_890 {
    public static void main(String[] args){
        String[] xx = {"ccc"};
        String par = "abb";
        findAndReplacePattern(xx,par);

    }
    public static List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new ArrayList<>();

        for(String str:words){
            boolean flag1 = true;
            boolean flag2 = true;
            Map<String,String> map = new HashMap<>();
            Map<String,String> map2 = new HashMap<>();
            for(int i = 0;i<str.length();i++){
                String s = str.substring(i,i+1);
                String p = pattern.substring(i,i+1);
                if(map.containsKey(p)){
                    //如果包含这个key,并且这个key和之前的映射逻辑不一样
                    if(!map.get(p).equals(s)){
                        flag1 = false;
                        break;
                    }
                }else {
                    //如果没有包含这个key则加进去
                    map.put(p,s);
                }

                if(map2.containsKey(s)){
                    if(!map2.get(s).equals(p))
                    {
                        flag2 = false;
                        break;
                    }
                }else {
                    map2.put(s,p);
                }
            }
            if(flag1 && flag2){
                result.add(str);
            }

        }
        return result;
    }
}
