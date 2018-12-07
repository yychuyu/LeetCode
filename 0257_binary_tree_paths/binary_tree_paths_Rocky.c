/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void binaryTreeSearch(struct TreeNode* node, int* route, int level, char **result, int *returnSize) {
    route[level] = node->val;
    
    if (node->left == NULL && node->right == NULL) {
        result[*returnSize] = (char *) malloc(sizeof(char) * 100);
        
        int j = 0;
        for(int i = 0; i < level + 1; i++) {
            j += sprintf(result[*returnSize] + j, "%d->", route[i]);
        }
        
        result[*returnSize][j-2] = '\0';
        (*returnSize)++;
        
        return 0;
    }
    else {
        if (node->left) binaryTreeSearch(node->left, route, level+1, result, returnSize);
        if (node->right) binaryTreeSearch(node->right, route, level+1, result, returnSize);        
    }
}


char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    if (!root) return NULL;
    int i;
    
    int *route = (int *) malloc(sizeof(int) * 100);
    char **result = (char **) malloc(100 * sizeof(char *));
    *returnSize = 0;
    
    binaryTreeSearch(root, route, 0, result, returnSize);

    return result;
}
