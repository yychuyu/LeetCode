class Solution {

/**
 * @param Integer[] $nums
 * @param Integer $target
 * @return Integer
 */
    function searchInsert($nums, $target) {
        $count = count($nums);
        if ($count == 0) return 0;
        if ($target > end($nums)) return $count;
        for ($i = 0; $i < $count; $i++) {
            if ($nums[$i] >= $target) {
                return $i;
            }
        }
    }
}
