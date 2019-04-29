class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0){
            return "";
        }
        // 获取数组中的第一个字符串
        String standard = strs[0];
        String result = "";
        // 遍历第一个字符串
        for (int i = 0;i < standard.length();i++){
            int counter = 0;
            // 从第二个字符串开始遍历数组
            for (int j = 1; j < strs.length;j++){
                // 获取数组第一个字符串的位置的字符串
                String first = standard.substring(i,i+1);
                
                if(i < strs[j].length()){
                    String second = strs[j].substring(i,i+1);
                    if (first.equals(second)){
                        counter += 1;
                        
                    }else{
                        break;
                    }
                }else{
                    break;
                }
  
            }
            if (counter == strs.length - 1){
                result = result + standard.substring(i,i+1);
            }else {
                break;
            }
        }
        return result;
   
    }
}