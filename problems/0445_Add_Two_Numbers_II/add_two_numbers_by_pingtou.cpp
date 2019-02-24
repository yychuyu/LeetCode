#include <iostream>
struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode *l1,ListNode *l2){
    ListNode dummy(-1);
    int carray = 0;
    ListNode *pa = l1;
    ListNode *pb = l2;
    ListNode * prev = &dummy;
    for(;pa != nullptr || pb != nullptr;
         pa = pa == nullptr?nullptr:pa->next,
         pb = pb == nullptr?nullptr:pb->next,
         prev = prev->next){
        const int p1 = pa == nullptr?0:pa->val;
        const int p2 = pb == nullptr?0:pb->val;
        int tmp = (p1 + p2 + carray)%10;
        carray = (p1 + p2 + carray)/10;
        prev->next = new ListNode(tmp);
    }
    if(carray != 0){
        prev->next = new ListNode(carray);
    }
    return dummy.next;
}

int main(){
    ListNode a1(2);
    ListNode a2(4);
    ListNode a3(3);
    a1.next = &a2;
    a2.next = &a3;

    ListNode b1(5);
    ListNode b2(6);
    ListNode b3(4);
    b1.next = &b2;
    b2.next = &b3;

    ListNode * p = addTwoNumbers(&a1,&b1);
    for(auto s = p;s != nullptr; s=s->next){
        std::cout << s->val << " ";
    }
    std::cout << std::endl;
    return 0;
}
