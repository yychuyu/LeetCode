
/*
 ��Ŀ���������
 
 ��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á����Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�

����������ʵ����Щ���ܣ�

    get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
    addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
    addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
    addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣
    deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ�
    
    ʾ����

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //�����Ϊ1-> 2-> 3
linkedList.get(1);            //����2
linkedList.deleteAtIndex(1);  //����������1-> 3
linkedList.get(1);            //����3
*/
class MyLinkedList {
    private:
        struct Node
        {
            int val;
            Node*next;
            Node(int va):val(va),next(NULL){}
        };
    int len;
    Node*head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(0);
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        Node*PCure = head;
        if(head == NULL)return -1;
        if(index >= len || index < 0)return -1;
        int i = 0;
        while(i <= index)
        {
            PCure = PCure->next;
            i++;
        }
         return PCure->val;
      
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if(head == NULL)return ;
        newnode->next = head->next;
        head->next = newnode;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node*newnode = new Node(val);
        Node*PCure = head;
        if(head == NULL)return ;
        while(PCure->next != NULL)
        {
            PCure = PCure->next;
        }
        PCure->next = newnode;
        newnode->next = NULL;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if(head == NULL)return ;
        if(index > len || len < 0)return ;
        if(index == len) 
        {
            return addAtTail(val);
        }
        Node*s = head;
        int i = 0;
        while(i < index)
        {
            s = s->next;
            i++;
        }
         Node*newnode = new Node(val);
        newnode->next = s->next;
        s->next = newnode;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(head == NULL)return ;
       if(index >= len || index < 0)return ;
        Node*s = head;
        int i = 0;
        while(i < index)
        {
            s = s->next;
            i++;
        }
        Node* p = s->next;
        s->next = p->next;
        delete p;
        len--;
    }
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
