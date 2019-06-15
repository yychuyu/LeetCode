/*

 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

示例 1:

输入: J = "aA", S = "aAAbbbb"
输出: 3
示例 2:
输入: J = "z", S = "ZZ"
输出: 0
22k
*/
class Solution {
    public int numJewelsInStones(String J, String S) {
    //将字符串转换成字符串数组
    char[] j = J.toCharArray();
    char[] s = S.toCharArray();
    //记录拥有的宝石数量
    int count = 0;
    for (int i = 0; i < j.length; i++) {
        for (int k = 0; k < s.length; k++) {
            if(j[i] == s[k]) {
                count ++;
            }
        }
    }
    return count;
    }
}