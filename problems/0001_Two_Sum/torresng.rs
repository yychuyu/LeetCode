use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        for (i, &v) in nums.iter().enumerate() {
            let t = target - v;
            if let Some(idx) = map.get(&t) {
                return vec![*idx as i32, i as i32];
            }
            map.insert(v, i);
        }
        vec![]
    }
}

fn main() {
    let nums: Vec<i32> = vec![2, 7, 11, 15];
    let target = 9;
    let res = Solution::two_sum(nums, target);
    println!("Given nums = [2, 7, 11, 15], target = 9");
    println!("{:?}", res);
}
