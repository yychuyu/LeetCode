
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curNode = root;
        vector<int> nodes;
        
        while (curNode != NULL) 
        {
            if (curNode -> left) 
            {
                TreeNode* predecessor = curNode -> left;
                while (predecessor -> right && predecessor -> right != curNode) 
                    predecessor = predecessor -> right;
                
                if ((predecessor -> right)==NULL) 
                {
                    predecessor -> right = curNode;
                    curNode = curNode -> left; 
                }
                else 
                {
                    predecessor -> right = NULL;
                    nodes.push_back(curNode -> val);
                    curNode = curNode -> right;
                }
            }
            else 
            {
                nodes.push_back(curNode -> val);  
                curNode = curNode -> right;  
            }
        }
        
        return nodes;
    }
};
