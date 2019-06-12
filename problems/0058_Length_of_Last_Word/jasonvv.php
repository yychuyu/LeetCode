class Solution {
    function lengthOfLastWord($s) {
        $tem = rtrim($s);
        $arr = explode(' ', $tem);
        return strlen(end($arr));
    }
}
