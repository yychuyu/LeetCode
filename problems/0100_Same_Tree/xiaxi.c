/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q)
    {
        return true;
    }
    else if(p && q)
    {
        if(p->val == q->val)
        {
            if(isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
}
