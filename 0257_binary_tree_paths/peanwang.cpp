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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> Path;
        string str(100,'0');
        DFShelp(root,Path,str,0);
        return Path;
    }
    void DFShelp(TreeNode* root,vector<string>& Path,string& a,int len){
        if(root == nullptr)
            return;
        else if(root->left== nullptr && root->right == nullptr){
            Path.push_back(a.substr(0,len)+to_string(root->val));
            return;
        }
        else{
            int i=0;
            for(auto ch:to_string(root->val))
                a[len+i++] = ch;
            a[len+i] = '-';
            i++;
            a[len+i] = '>';
            DFShelp(root->left,Path,a,len+i+1);
            DFShelp(root->right,Path,a,len+i+1);
        }
            
    }
};