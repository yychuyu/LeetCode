class Solution {
    public int rotatedDigits(int N) {
        int answer = 0;
        for(int i=0;i<=N;i++) { //数字中包含2、5、6、9，而不含3、4、7的都是好数
            String str = String.valueOf(i);
            if((str.contains("2")||str.contains("5")||str.contains("6")||str.contains("9"))&&(!str.contains("3")&&!str.contains("7")&&!str.contains("4"))) {
                answer++;
            }
        }
        return answer;
    }
}