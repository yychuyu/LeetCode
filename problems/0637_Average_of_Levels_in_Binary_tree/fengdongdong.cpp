/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    #二叉树非完全二叉树
    #先用队列保存节点，然后push和pop节点，过程中再求平均值
    #①层次遍历
    #②计算对应层的均值
    //需要逐层操作，不能逐个节点操作；一次循环只能一层入队列（每次while，队列中只有一层的元素），后求该层的和，后pop该层元素，每个元素pop之前子节点先入队列
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> nodeque;
        nodeque.push(root);
            while(nodeque.size()){   
                queue<TreeNode*> tempque=nodeque;
                double result_=0.0;
                int count=tempque.size();
                TreeNode* node;
                for(;tempque.size();){
                    result_ +=tempque.front()->val; 
                    node=nodeque.front();
                
                    if(node&&node->left) nodeque.push(node->left);
                    if(node&&node->right) nodeque.push(node->right);
                    
                    nodeque.pop();
                    tempque.pop();
                    
                }
                result_=result_/count;
                result.push_back(result_);
        }
        return result;
    }
};
