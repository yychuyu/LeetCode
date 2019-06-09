## 题目描述
```text
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
说明:
如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
```
## 解题思路

```text
判断二叉树是否是平衡树，比如有两个节点n1, n2，我们需要比较n1的左子节点的值和n2的右子节点的值是否相等，
同时还要比较n1的右子节点的值和n2的左子结点的值是否相等，以此类推比较完所有的左右两个节点。
因此我们可以用递归的方法来实现
```

## 代码实现
```java
/**
 * 给定一个二叉树，检查它是否是镜像对称的。
 */
public class Solution {
    //需满足下列两个条件：
    //它们的两个根结点具有相同的值。
    //每个树的右子树都与另一个树的左子树镜像对称。
    public boolean isSymmetric(TreeNode root) {
        if (root==null) return true;//条件都符合，已经没有下一个，直接返回
        return check(root,root);
    }
    public boolean check(TreeNode left,TreeNode right){
        if (left==null&&right==null)return true;
        if (left==null||right==null)return false;//如果只有一个为null就返回false
        return (left.val==right.val)&&check(left.left,right.right)&&check(left.right,right.left);
    }

}
```
