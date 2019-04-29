class Solution {
    private String vowels = "AEIOUaeiou";  // 需要包含大小写
    int wordIndex = 0;
    
    private String process(String word) {
        String result = "";
        
        if (vowels.contains(word.charAt(0)+"")) {  // 是否为元音字母开头
            result = word+"ma";
        } else {
            result = word.substring(1, word.length())+word.charAt(0)+"ma";
        }
        
        for (int i=0; i<this.wordIndex; i++) {  // 追加字母 a
            result += "a";
        }
        
        return result;
    }
    
    public String toGoatLatin(String S) {
        String [] words = S.split(" ");  // 按空格切割句子
        String result = "";
        
        for (String word:words) {  // 按单词处理
            this.wordIndex += 1;
            result += this.process(word)+" ";
        }
        
        return result.substring(0, result.length()-1);  // 把最后多余的空格除外
    }
}
