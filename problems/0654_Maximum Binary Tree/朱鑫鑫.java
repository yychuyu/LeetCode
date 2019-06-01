/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        TreeNode root = buildTree(nums,0,nums.length-1);
        return root;
    }
    
    public TreeNode buildTree(int[] nums, int start, int end){
        int index = start;
        TreeNode tree = new TreeNode(nums[index]);     
        
        //找出最大元素的下标
        for(int i=start; i<=end; i++){
            if(nums[index] < nums[i]){
                index = i;
            }
        }
        tree.val = nums[index];
        
        if(index > start){
            tree.left = buildTree(nums,start,index-1);
        }
        if(index < end){
            tree.right = buildTree(nums,index+1,end);
        }
        
        return tree;
    }
}