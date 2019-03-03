/*
题目描述：

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

import java.util.ArrayList;
import java.util.List;

class Solution890{
    public boolean isMatch(String word,String pattern){
        int[] map = new int[138];
        int[] isUse = new int[138];
        for(int i = 0;i < word.length();i ++){
            int p = pattern.charAt(i);
            int s = word.charAt(i);
            if(map[p] == 0 && isUse[s] ==0){
                map[p] = s;
                isUse[s] =1;
            }else if(map[p] !=s){
                return false;
            }
        }
        return true;
    }
    public List<String> findAndReplacePattern(String[] words, String pattern){
        List<String> list = new ArrayList<>();
        for(int i = 0;i < words.length;i ++){
            if(words[i].length()==pattern.length()){
                if(isMatch(words[i],pattern))
                    list.add(words[i]);
            }
        }
        return list;
    }
    //测试代码
    public static void main(String[] args){
        String[] arr = {"abc","deq","mee","aqq","dkd","ccc"};
        String pattern = "abb";
        Solution890 solution = new Solution890();
        System.out.println(solution.findAndReplacePattern(arr,pattern));
    }
}

