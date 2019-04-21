import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * @Author: Json Wan
 * Created at: 2019/3/13.
 * Description:
 * 22. Generate Parentheses
 * Medium
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * [
 * "((()))",
 * "(()())",
 * "(())()",
 * "()(())",
 * "()()()"
 * ]
 * 思路：
 * 1.最简单的思路：从所有的组合中过滤出合适的即可，C(2n,n)，复杂度n!；
 * 2.树按条件分形算法，能够保证不重复，分形条件：
 * （1）左右括号数量均不能超过n；
 * （2）右括号数量至多等于左括号数量。
 */

public class wanxu_pursue_0022 {
    List<String> list = new ArrayList<String>();

    //思路差不多，每一次放置，需要改变左右括号累积数量并传递给下一次放置作为参考。
    public List<String> bestGenerateParenthesis(int n) {
        if (n <= 0) {
            return new ArrayList<String>();
        }
        backtrack("", 0, 0, n);
        return list;
    }

    public void backtrack(String s, int open, int closed, int parensLeft) {
        if (parensLeft == open && parensLeft == closed) {
            list.add(s);
        }
        if (open < parensLeft) {
            backtrack(s + "(", open + 1, closed, parensLeft);
        }
        if (closed < open && closed < parensLeft) {
            backtrack(s + ")", open, closed + 1, parensLeft);
        }
    }

    class TreeNode {
        int leftCount;
        int rightCount;
        String sequence;

        public TreeNode(int leftCount, int rightCount, String sequence) {
            this.leftCount = leftCount;
            this.rightCount = rightCount;
            this.sequence = sequence;
        }
    }

    //AC,0.2031,
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode root = new TreeNode(1, 0, "(");
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            //终止条件判断
            if (node.leftCount == n && node.rightCount == n) {
                result.add(node.sequence);
            } else if (node.leftCount == n) {
                //分化出一个节点
                queue.add(new TreeNode(node.leftCount, node.rightCount + 1, node.sequence + ")"));
            } else if (node.leftCount > node.rightCount) {
                //分化出两个节点
                queue.add(new TreeNode(node.leftCount + 1, node.rightCount, node.sequence + "("));
                queue.add(new TreeNode(node.leftCount, node.rightCount + 1, node.sequence + ")"));
            } else {
                //分化出一个节点
                queue.add(new TreeNode(node.leftCount + 1, node.rightCount, node.sequence + "("));
            }
        }
        return result;
    }

    public static void main(String[] args) {
        wanxu_pursue_0022 instance = new wanxu_pursue_0022();
        System.out.println(instance.generateParenthesis(1));
        System.out.println(instance.generateParenthesis(2));
        System.out.println(instance.generateParenthesis(3));
        System.out.println(instance.generateParenthesis(4));
    }
}
