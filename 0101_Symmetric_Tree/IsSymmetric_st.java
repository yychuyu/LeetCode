package algorithm._101_isSymmetric;

import java.util.ArrayList;
import java.util.List;
/*
����һ����������������Ƿ��Ǿ���ԳƵġ�
	���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�
    1
   / \
  2   2
 / \ / \
3  4 4  3

	����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:
    1
   / \
  2   2
   \   \
   3    3
˵��:�����������õݹ�͵������ַ������������⣬��ܼӷ֡�
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

	//˼· : �ж��Ƿ���Գ�,���ж����������������Ƿ��ǶԳƵļ���,Ӧ�ø��϶���һ����,
	//		������ݹ�����Ļ��Ѹ�����ȥ��������������,�����������Ƚ�,���Ը�û��Ҫ�Ƚ�,
	//		�����������ø�--��--��ȥ����,���������������ø�--��--��ȥ����,
	//		��Listȥ�洢������Ľ��,�����Ӧ�ĵ�ֵ�����������Ǿ���ԳƵ�,
	//		��Integerȥ�洢����ֵ����ΪInteger�ܹ��洢null
	//�ⷨ : 69-81��ʵ���˱����������ķ���,83-94ʵ���˱����������ķ���,
	// 		46-54���ж��������:��Ϊ��,����������Ϊ��,Ϊtrue;��������ֻ��һ��Ϊ��,Ϊfalse;
	//		��������List<Integer>���洢��������������Ľ��	,
	//		�Ƚ�����List<Integer>��ÿһ����Ӧ��ֵ�Ƿ�������жϸ����Ƿ��Ǿ���ԳƵ�
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