class Solution{
public:
    TreeNode* sortedListToBST(ListNode* head){
        vector<int> vec;
        while(head!=NULL){
            vec.push_back(head->val);
            head = head -> next;
        }
        return createBST(vec,0,vec.size()-1);
    }
    TreeNode* createBST(vector<int>&vec ,int left,int right){
        if(left>right)
            return NULL;
        int mid = (1/2.0)*(left+right);
        TreeNode* root = new TreeNode(vec[mdf]);
        root->left = createBST(vec,left,mid-1);
        root->right = createBST(vec,mid+1,right);
        return root; 
    }
};
