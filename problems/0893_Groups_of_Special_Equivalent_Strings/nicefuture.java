/*
E.g. [“abcd”,”cdab”,”adcb”,”cbad”] are all in the same graph.

“abcd”: odd “ac”, even: “bd”
“cdab”: odd “ac”, even: “bd”
“adcb”: odd “ac”, even: “bd”
“cbad”: odd “ac”, even: “bd”

source: https://zxi.mytechroad.com/blog/string/leetcode-893-groups-of-special-equivalent-strings/
*/

class Solution {
    public int numSpecialEquivGroups(String[] A) {
        HashSet<String> uni = new HashSet();
        for (String s:A) {
            char[] odd = new char[26];
            char[] even = new char[26];
            for (int i=0; i<s.length(); i++) {
                if (i % 2  == 0) even[s.charAt(i)-'a']++;
                else odd[s.charAt(i)-'a']++;
            }
            uni.add(Arrays.toString(odd)+Arrays.toString(even));
        }
        return uni.size();
    }
}
