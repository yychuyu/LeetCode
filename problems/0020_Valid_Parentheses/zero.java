class Solution {
    public boolean isValid(String s) {
                char[] left = {'(','{','['};
        char[] right = {')','}',']'};
        char[] charArray = s.toCharArray();

        ArrayList<Character> characters = new ArrayList<>();
        // 将字符串中所有的括号插入到 characters 中
        for (int i = 0; i < charArray.length; i++) {
            if(charArray[i] == '(' || charArray[i] == ')' || charArray[i] == '{' || charArray[i] == '}' || charArray[i] == '[' || charArray[i] == ']' ){
                characters.add(charArray[i]);
            }
        }
        for (int i = 0; i < characters.size(); i++) {

            // 判断该字符是否是`右`括号
            if (characters.get(i) == ')' || characters.get(i) == '}' || characters.get(i) == ']'){

                if (i <= 0) {
                    return false;
                }
                char temp_left = characters.get(i - 1);
                char temp_right = characters.get(i);
                int m=0,n=0;
                for (int i1 = 0; i1 < left.length; i1++) {
                    if (temp_left == left[i1]) {
                        m = i1;
                    }
                }
                for (int i1 = 0; i1 < right.length; i1++) {
                    if (temp_right == right[i1]) {
                        n = i1;
                    }
                }
                if (m == n){
                    characters.remove(i);
                    characters.remove(i - 1);

                }else {
                    return false;
                }
                i-=2;
            }
        }
        if (characters.size() > 0) {
            return false;
        } else {
            return true;
        }

    }
}