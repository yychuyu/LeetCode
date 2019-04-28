class Solution {
    String [] table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    public int uniqueMorseRepresentations(String[] words) {
        // use java set
        Set<String> result = new HashSet();
        for (String word: words) {
            String s = "";
            for (int i=0; i<word.length(); i++) {
                s += this.table[word.charAt(i)-'a'];
            }
            result.add(s);
        }
        return result.size();
    }
}
