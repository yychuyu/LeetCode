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
    //涉及string 操作
    //对一颗二叉树而言，根节点到每个叶节点的路径是唯一的
    //路径数就是叶节点数
    //据题意思就是遍历二叉树，在叶节点时保存到达该节点的路径
    //两个模块，一个是判断何为叶节点，一个是遍历时如何保存正确路径
    //vector<int> push_int(TreeNode* root){vector<int> int_path;};
    
    // 新接口，有新参数

    vector<string> recursion_operate(TreeNode* root,vector<int> int_path,vector<string> str_path){
        
        int_path.push_back(root->val);
        //叶节点处 int转str
        if(!root->left&&!root->right){
            vector<int>::iterator item=int_path.begin();
            string arrow="->",temp="";
            
            for(;item!=int_path.end()-1;item++)
                temp+=to_string(*item)+arrow;

            temp+=to_string(*(int_path.end()-1));
            str_path.push_back(temp);
            return str_path;
        }       
        //将叶节点所在路径所经过的元素值放入int_path
        if(root->left)
            str_path = recursion_operate(root->left,int_path,str_path);
        
        if(root->right)
            str_path = recursion_operate(root->right,int_path,str_path);

        return str_path;    
    }
    
    vector<string> binaryTreePaths(TreeNode* root){ 
        vector<string> result;
        if(!root) return result;
        else{
            vector<int> int_path;
            vector<string> str_path;
            result=recursion_operate(root,int_path,str_path);
        }
        return result;
    }
};
