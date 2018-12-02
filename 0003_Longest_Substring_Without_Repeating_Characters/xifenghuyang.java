
/**
 * 注：暂时提供暴力解发，LeetCode提示timeout。
 * 下周更新优化方法。
 */
public class xifenghuyang {

    public int lengthOfLongestSubstring(String s) {
        int result = 0;
        for(int i=0; i<s.length();i++){
            for(int j=1; j<s.length()-i+1;j++){
                String temp = s.substring(i,i+j);
                if(isUnique(temp)){
                    if(temp.length()>result){
                        result = temp.length();
                    }
                }
            }
        }
        return result;
    }

    public boolean isUnique(String s1){
        StringBuffer unique = new StringBuffer();
        for(int i=0; i<s1.length(); i++){
            if(unique.indexOf(""+s1.charAt(i))!= -1){ return false;
            }else{
                unique.append(s1.charAt(i));
            }
        }
        return true;
    }

    public static void main(String[] args){

        xifenghuyang xifeng = new xifenghuyang();

//        String test1 = "abcabcbb";
//        String test1 = " ";   //1
        String test1 = "au";   //2
        int test1Answer;
        test1Answer = xifeng.lengthOfLongestSubstring(test1);
        System.out.println(test1Answer);
    }
}
