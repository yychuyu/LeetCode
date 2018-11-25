class MyLinkedList {
public:
    struct ListNode {
        int val;
        int length;
        ListNode *tail;
        ListNode *next;
        ListNode(int n = 0):val(n), length(0), tail(nullptr), next(nullptr){}
    };
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        pHead = new ListNode(-1);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= pHead->length || index < 0) return -1;
        
        ListNode *p = pHead->next;
        for (int i = 0; i < index; ++i)
        {
            p = p->next;
        }
        
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *pNew = new ListNode(val);
        if (pHead->next == nullptr)
        {
            
            pHead->tail = pNew;
        }
        
        pNew->next = pHead->next;
        pHead->next = pNew;
        
        pHead->length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *pTail = new ListNode(val);
        if (pHead->tail == nullptr)
        {
            pHead->tail = pTail;
            pTail->next = pHead->next;
            pHead->next = pTail;
        }
        else
        {
            pHead->tail->next = pTail;
            pHead->tail = pTail;
        }
        
        pHead->length++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == pHead->length)     // equal
        {
            addAtTail(val);
        }
        else if (index > pHead->length)
        {
            return;
        }
        else
        {
            ListNode *p = pHead->next;
            for (int i = 0; i < index - 1; ++i)
            {
                p = p->next;
            }
            
            ListNode *pNew = new ListNode(val);
            pNew->next = p->next;
            p->next = pNew;
            
            pHead->length++;
        }
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= pHead->length || index < 0) return;
        
        ListNode *p = pHead->next;
        for (int i = 0; i < index - 1; ++i)
        {
            p = p->next;
        }
    
        if (index == pHead->length - 1)
        {
            pHead->tail = p;
        }
        
        ListNode *del = p->next;
        p->next = del->next;
        pHead->length--;
        
        del->tail = nullptr;
        del->next = nullptr;
        delete del;
    }
    
private:
    ListNode *pHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
