class Solution {
    public int minDepth(TreeNode root){
        //子节点为null返回0
        if(root==null) return 0;
        //左右节点递归调用        
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        //比较左右节点，返回小的那个深度
        return (left==0||right==0)?left+right+1:Math.min(left,right)+1;
    }   
}