package algorithm._102_levelOrder;

import java.util.ArrayList;
import java.util.List;
/*
����һ���������������䰴��α����Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��
����:
	����������: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
�������α��������
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

	//˼· : ����α���,������Ҫ����һ��������ʾ��ǰ��������Ԫ����������һ���,
	//		����ArrayList�е�get()��ȡ��ǰ���ڲ��List�����������м��뵱ǰ������ֵ
	//		��Ϊ����������������µ�,���Ե�ǰ�������Ĳ�ֻ�������һ���֮ǰ�Ĳ�,
	//		���ֻ��Ҫ�ж�List�еĲ����Ƿ����С�ڵ�ǰ�Ĳ�-1(������0��ʼ�����-1)
	//		���ж��Ƿ�����һ��List�ļ�������ŵ�ǰ�������,
	//		ͬʱ������get()���ֿ�ָ������,���������Ҳ���������ҵ�,
	//		���Ը��ݱ�����˳��,����ǰ��List���������Ԫ��ֵ����
	//�ⷨ : ����һ��tier����ʾ��ǰ������Ԫ�����ڵĲ�,
	//		49-62��ʵ���˲�α���,ÿ������һ�������Ӹ�ʱ��tier++��ʾ���뵽����һ��,
	//		56-58���жϴ�ŵ�ǰ��Ԫ�ص�List�����Ƿ����,���������½�һ��,
	//		60����������ŵ�ǰ���List�����д�ŵ�ǰ������Ԫ��
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
