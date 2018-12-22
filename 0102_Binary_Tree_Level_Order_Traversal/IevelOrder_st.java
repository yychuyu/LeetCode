package algorithm._102_levelOrder;

import java.util.ArrayList;
import java.util.List;
/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
例如:
	给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
	[
  		[3],
  		[9,20],
  		[15,7]
	]
*/

public class IevelOrder {
	public static void main(String[] args) {
		TreeNode root = new TreeNode(3);
		root.left = new TreeNode(9);
		root.right = new TreeNode(20);
		root.right.left = new TreeNode(15);
		root.right.right = new TreeNode(7);
		List<List<Integer>> list = levelOrder(root);
		System.out.println(list);
	}

	//思路 : 按层次遍历,所以需要定义一个数来表示当前所遍历的元素是属于哪一层的,
	//		调用ArrayList中的get()获取当前所在层的List集合再往其中加入当前遍历的值
	//		因为先序遍历是由上往下的,所以当前所遍历的层只会是最后一层或之前的层,
	//		因此只需要判断List中的层数是否等于小于当前的层-1(索引从0开始引起的-1)
	//		来判断是否已有一个List的集合来存放当前层的数据,
	//		同时避免了get()出现空指针的情况,且先序遍历也是由左往右的,
	//		所以根据遍历的顺序,往当前的List集合逐渐添加元素值即可
	//解法 : 定义一个tier来表示当前遍历的元素所在的层,
	//		49-62行实现了层次遍历,每进入下一个左右子根时令tier++表示进入到了下一层,
	//		56-58行判断存放当前层元素的List集合是否存在,不存在则新建一个,
	//		60行则是往存放当前层的List集合中存放当前遍历的元素
	public static List<List<Integer>> levelOrder(TreeNode root) {
		int tier = 0;
		List<List<Integer>> list = new ArrayList<List<Integer>>();
		order(list, root, tier);
		return list;
	}

	public static List<List<Integer>> order(List<List<Integer>> list,
			TreeNode root, int tier) {
		tier++;
		if (root == null) {
			return list;
		}
		if (list.size() <= tier - 1) {
			list.add(new ArrayList<Integer>());
		}
		list.get(tier - 1).add(root.val);
		order(list, root.left, tier);
		order(list, root.right, tier);
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
