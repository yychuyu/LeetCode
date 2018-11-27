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
    //²âÊÔÓÃÀý
    public static void main(String[] args){
        String[] arr = {"abc","deq","mee","aqq","dkd","ccc"};
        String pattern = "abb";
        Solution890 solution = new Solution890();
        System.out.println(solution.findAndReplacePattern(arr,pattern));
    }
}

