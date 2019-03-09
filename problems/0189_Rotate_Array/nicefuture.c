//参考讨论区的
void rotate(int* nums, int numsSize, int k) {
    int numsCopy[numsSize];
    memcpy(&numsCopy, nums, numsSize*sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        nums[(i+k)%numsSize] = numsCopy[i];
    }
}

/*循环双链表
typedef struct _node
{
    struct _node *plast;
    int value;
    struct _node *pnext;
} Node;
 
typedef struct _list
{
    struct _node *phead;
    struct _node *ptail;
    int total;
} List;
        
//初始化    
void InitializeList(List *list)
{
    list->phead = list->ptail = NULL;
    list->total = 0;
}            
                  
//增加节点          
void AddNode(List *list, int value)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if (p != NULL) {
        p->plast = list->ptail;
        p->value = value;
        p->pnext = list->phead;
        
        if(list->phead == NULL) {   //无头节点时
            list->phead = list->ptail = p;
            list->phead->plast = list->ptail->pnext = p;
        } else {                    //存在头节点时
            list->ptail = (list->ptail)->pnext = p;
            list->phead->plast = list->ptail;
        }   
    } else {
        exit(1);
    }   
}


//循环双链表
void rotate(int* nums, int numsSize, int k) {
    List list;
    InitializeList(&list);
            
    for (int i = 0; i < numsSize; i++) {
        AddNode(&list, nums[i]);
    }
    
    while (k > 0) {
        list.phead = list.phead->plast;
        list.ptail = list.ptail->plast;
        k--;
    }
    
    Node *p = list.phead;
    int i = 0;
    while (p != NULL) {
        nums[i] = p->value;
        if (p == list.ptail) break;
        p = p->pnext;
        i++;
    }
}
*/

/*  直接插入
void insert(int *nums, int numsSize, int num, int index) {
    for (int i = numsSize-1; i > index; i--) {
        nums[i] = nums[i-1];
    }
    nums[index] = num;
}

void rotate(int* nums, int numsSize, int k) {
    while (k > 0) {
        insert(nums, numsSize, nums[numsSize-1], 0);
        k--;
    }
}
*/
