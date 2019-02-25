package algorithm._101_isSymmetric;

import java.util.ArrayList;
import java.util.List;
/*
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
说明:如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/

public class IsSymmetric {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(2);
		root.left = new TreeNode(3);
		root.right = new TreeNode(3);
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(5);
		root.right.left = new TreeNode(5);
		root.right.right = new TreeNode(4);
		root.left.right.left = new TreeNode(8);
		root.left.right.right = new TreeNode(9);
		root.right.left.left = new TreeNode(9);
		root.right.left.right = new TreeNode(8);
		System.out.println(isSymmetric(root));
	}

	//思路 : 判断是否镜像对称,则判断左子数与右子数是否是对称的即可,应该跟肯定是一样的,
	//		且如果递归遍历的话把根传进去则会遍历了整个树,这样不好做比较,所以根没必要比较,
	//		遍历左子树用根--左--右去遍历,而遍历右子树则用根--右--左去遍历,
	//		用List去存储遍历后的结果,如果对应的的值都相等则该树是镜像对称的,
	//		用Integer去存储树的值是因为Integer能够存储null
	//解法 : 69-81行实现了遍历左子树的方法,83-94实现了遍历右子树的方法,
	// 		46-54行判断特殊情况:根为空,左右子树都为空,为true;左右子树只有一个为空,为false;
	//		定义两个List<Integer>来存储左右子树遍历后的结果	,
	//		比较两个List<Integer>中每一个对应的值是否相等来判断该树是否是镜像对称的
	public static boolean isSymmetric(TreeNode root) {
		if (root == null) {
			return true;
		}
		if (root.left == null || root.right == null) {
			if (root.left != null || root.right != null) {
				return false;
			}
			return true;
		}
		List<Integer> listLeft = new ArrayList<Integer>();
		List<Integer> listRight = new ArrayList<Integer>();
		orderLeft(root.left, listLeft);
		orderRight(root.right, listRight);
		for (int i = 0; i < listLeft.size(); i++) {
			if (listLeft.get(i) != listRight.get(i)) {
				return false;
			}
		}
		return true;
	}

	public static List<Integer> orderLeft(TreeNode root, List<Integer> list) {
		if (root == null) {
			list.add(null);
			return list;
		}
		list.add(root.val);
		if (root.left == null && root.right == null) {
			return list;
		}
		orderLeft(root.left, list);
		orderLeft(root.right, list);
		return list;
	}

	public static List<Integer> orderRight(TreeNode root, List<Integer> list) {
		if (root == null) {
			list.add(null);
			return list;
		}
		list.add(root.val);
		if (root.left == null && root.right == null) {
			return list;
		}
		orderRight(root.right, list);
		orderRight(root.left, list);
		return list;
	}
}

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}