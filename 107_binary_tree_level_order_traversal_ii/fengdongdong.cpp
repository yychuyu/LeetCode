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
    //逆序result
    vector<vector<int>> reverse(vector<vector<int>> result){
        int size=result.size()-1;
        int j=0,i=size,count=0;
        for(;count<(size+1)/2;count++){
            vector<int> temp=result[j];
            result[j++]=result[i];
            result[i--]=temp;
        }
        return result;
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        queue<TreeNode*> nodeque,tempque;
        nodeque.push(root);
        vector<int> intemp;

        while(nodeque.size()){//不直接使用nodeque，而是通过再创建一个tempque简化操作
            
            tempque = nodeque;
            
            for(;tempque.size()!=0;){
                intemp.push_back(tempque.front()->val);
                
                TreeNode* nodetemp=nodeque.front();//tempque.front()==noteque.front()
                if(nodetemp->left) nodeque.push(nodetemp->left);
                if(nodetemp->right) nodeque.push(nodetemp->right);
                tempque.pop();
                nodeque.pop();
            }
            //不需要对tempque清空，因为已经空
            result.push_back(intemp); 
            intemp.clear();           
        }
        return reverse(result);
    }
};
