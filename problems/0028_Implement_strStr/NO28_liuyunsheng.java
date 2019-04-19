package leetcodePart5;

/**
 * @author 刘云生
 * @date 2019/4/917:31
 */
public class NO28_liuyunsheng {
    public static void main(String[] args) {
        System.out.println(NO28_liuyunsheng.removeElement("a","a"));
    }
    public static int removeElement(String haystack,String needle){
        if (needle.length()==0){
            return 0;
        }else if (haystack.length()==0){
            return -1;
        }else {
            int num=-1;
            int length=needle.length();
            for (int i = 0; i <haystack.length()-length+1 ; i++) {
                String substring=haystack.substring(i,i+length);
                if (substring.equals(needle)){
                    num=i;
                    break;
                }
            }
            return num;
        }
    }
    
}
