//典型的层序遍历，BFS法
int* largestValues(struct TreeNode* root, int* returnSize){
    struct TreeNode **queue = (struct TreeNode **)malloc(10000*sizeof(struct TreeNode *));
    int front=0,rear=0,middle;
    int depth=0,i=0;
    int arry[1000];
    if(root!=NULL)
    queue[rear++]=root;
    middle = rear;
    while(front!=rear){
        int temp=queue[front]->val;
        for(;front!=middle;++front){
            if(queue[front]->left!=NULL)
                queue[rear++]=queue[front]->left;
            if(queue[front]->right!=NULL)
                queue[rear++]=queue[front]->right;
            if(temp < queue[front]->val)
                temp = queue[front]->val;
        }
        middle = rear;
        arry[depth++]=temp;
    }
    *returnSize = depth;
    int *result = (int *)malloc(depth*sizeof(int));
    for(;i<depth;i++){
        result[i] = arry[i];
    }
    return result;    
}
