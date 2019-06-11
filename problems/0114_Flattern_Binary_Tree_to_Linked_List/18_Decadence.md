## 题目
```
leetcode114 将二叉树变为链表
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
给定一个二叉树，原地将它展开为链表。
例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6

将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

```
## 解题思路
```text
由题图易知，将二叉树化为链表就是把二叉树变为只有右子树的二叉树。而按照这样的思路，我们用递归很快就可以完成。
如果存在左子树，把右子树保留，右子树置换成左子树，左子树置空
找到该树的最终节点，即最右节点，再链接开始保留的右子树，即根节点
```

### python3
```text
class Solution:
    def flatten(self, root: TreeNode) -> None:
        if not root:
            return
        self.flatten(root.left)
        self.flatten(root.right)
        if root.left:
            tmp = root.right
            root.right = root.left
            root.left = None
            node = root.right
            while node.right:
                node = node.right
            node.right = tmp
```


### Java
```java
class Solution{
    public void flatten(TreeNode root) {
        while (root != null) {
            if (root.left != null) {
                TreeNode pre = root.left;
                while (pre.right != null)
                    pre = pre.right;
                pre.right = root.right;
                root.right = root.left;
                root.left = null;
            }
            root = root.right;
        }
    }
}
```