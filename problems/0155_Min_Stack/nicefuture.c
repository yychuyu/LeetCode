/*
    push: x > min, push(x-min); x < min, push(x-min), min = x;
    peek: x > 0, return x+min; x < 0, return min
     pop: x > 0, pop; x < 0, min = min-x, pop 
  getMin: x > 0, return min; x < 0, return min
    
    
*/


typedef struct node {
    long val;  //注意变量类型
    struct node *next;
} Node;
typedef struct {
    Node *top;
    int total;
    int maxSize;
    long min;  //保存栈当前最小值
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
    MinStack *minstack = (MinStack*) malloc(sizeof(MinStack));
    minstack->top = NULL;
    minstack->total = 0;
    minstack->maxSize = maxSize;
    minstack->min = 0;
    return minstack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->total == obj->maxSize) return;
    
    Node *p = (Node*) malloc(sizeof(Node));
    p->val = x;
    p->next = NULL;
    
    //判断是否要更新栈最小值
    if (obj->top == NULL) {
        obj->top = p;
        obj->min = x;
    }
    else {
        p->val = (long)x-obj->min;
        if (x < obj->min) obj->min = x;
        p->next = obj->top;
        obj->top = p;
    }
    obj->total += 1;
    
    // printf("meet%d, pushed%d, min=%d\n", x, obj->top->val, obj->min);
}

void minStackPop(MinStack* obj) {
    if (obj->top == NULL) return;
    
    //判断是否更新min
    if (obj->top->val < 0) obj->min -= obj->top->val;
    obj->top = obj->top->next;
    obj->total -= 1;
}

int minStackTop(MinStack* obj) {
    if (obj->total == 1) return obj->min;
    
    int tar = 0;
    
    if (obj->top->val >= 0) {
        tar = (int)(obj->top->val + obj->min);
    } else {
        tar = (int)(obj->min);
    }
    
    return tar;
}

int minStackGetMin(MinStack* obj) {
    return (int)(obj->min);
}

void stackFree(Node *p) {
    if (p == NULL) return;
    stackFree(p->next);
    free(p);
}
void minStackFree(MinStack* obj) {
    stackFree(obj->top);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
