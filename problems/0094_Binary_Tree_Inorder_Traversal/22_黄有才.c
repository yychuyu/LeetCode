/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     struct TreeNode *left;
 *      *     struct TreeNode *right;
 *       * };
 *        */


/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */

/******************************************************************************************************************************
 * 思路1：第归遍历二叉树，每记录一个节点就重新realloc节点数组；以returnSize记录节点书来嗯，并对数组下标进行索引
 * TC: O(n)
 * SC: O(n)
 * ****************************************************************************************************************************/
void Recursively_Traversal(struct TreeNode* root, int **array, int *returnSize)
{
	if(root)
	{
		Recursively_Traversal(root->left, array, returnSize);
		++(*returnSize);
		*array = (int *) realloc(*array, sizeof(int)*(*returnSize));
		(*array)[*returnSize-1] = root->val;
		Recursively_Traversal(root->right, array, returnSize);
	}
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	if(!root)	return NULL;
	int *array = (int *) malloc(sizeof(int));
	Recursively_Traversal(root, &array, returnSize);
	return array;
}



/******************************************************************************************************************************
 * 思路2：迭代遍历，用栈临时存放前序节点；其他与第归方法相同
 * TC： O(n)
 * SC:  O(n)
 * ****************************************************************************************************************************/
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	if(!root)	return NULL;
	int *array = (int *) malloc(sizeof(int));
	struct TreeNode **stack = (struct TreeNode **) malloc(sizeof(struct TreeNode*));		//用于存放前序节点的栈
	int top = 0;
	int stack_size = 1;
	stack[top++] = root;
	struct TreeNode *pop = NULL; 				//存放弹栈后的节点地址								
	while( 0 != top ) 
	{
		while( root->left )				//以当前root为根，找到最左叶子节点，过程中经过的节点入栈以便找回
		{			
			root = root->left;
			stack = (struct TreeNode **) realloc(stack, sizeof(struct TreeNode*)*(++stack_size));
			stack[top++] = root;
		}
		while( 0 != top )
		{
			pop = stack[--top];
			++(*returnSize);
			array = (int *) realloc(array, sizeof(int)*(*returnSize));
			array[*returnSize-1] = pop->val;
			if(pop->right)				//若当前节点存在右子树，将其右子树入栈，并作为当前root重新开始寻找
			{
				root = pop->right;
				stack[top++] = root;
				break;		
			}
		}
	}
	return array;
}



/******************************************************************************************************************************
 * 参考Solution和Discussion后的另一种解法
 * 思路3：迭代构造线索二叉树结构：
 * 	检查当前root是否存在左子树 —— 若是，找到左子树的最右叶子节点，使其右子树（此时为NULL）连接到当前root，再以root->left为新的root再次判断；
 * 				      若否，直接存入数组，以root->right为新的root重新检查
 * TC： O(n)
 * SC:  O(1)
 * ****************************************************************************************************************************/
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = 0;
	if(!root)	return NULL;
	int *array = (int *) malloc(sizeof(int));
	struct TreeNode *cur = NULL;
	struct TreeNode *thread_tag = NULL;
	while( root )
	{
		while( root->left ) 
		{
			cur = root->left;
			while( cur->right && cur != thread_tag )		//找到当前root左子树的最右叶子节点
			{
				cur = cur->right;
			}
			if( cur == thread_tag )					//判断此root是否通过线索找到（已经检查过），若是，直接进入if存入数组
			{	
				break;
			}			
			cur->right = root;					//使最右叶子节点连接到当前root（中序遍历的顺序）
			root = root->left;					//更新左子树为当前root
		}
		if( root )
		{
			++(*returnSize);
			array = (int *) realloc(array, sizeof(int)*(*returnSize));
			array[*returnSize-1] = root->val;
			thread_tag = root;						//线索标记，若右指针是线索而非节点指针，则通过while查找后的最右叶子为flag
			root = root->right;
		}
	}
	return array;
}
