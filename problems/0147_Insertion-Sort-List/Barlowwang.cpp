
/**
* LeetCode The 147th problem :insertion-sort-list
* Auth:Barlowwang
* Date:2019-03-16
**/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *insertionSortList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    ListNode *tail, *p, *q;
    p = head->next;
    tail = head;
    while (p != NULL)
    {
        q = head;
        if (p->val <= head->val)
        {
            tail->next = p->next;
            p->next = head;
            head = p;
             p = tail->next;
            continue;
        }
        while (q != tail)
        {
            if (q->next->val > p->val)
            {
                tail->next = p->next;
                p->next = q->next;
                q->next = p;
                break;
            }
            q = q->next;
        }
        if (q == tail)
        {
            tail = tail->next;
        }
        p = tail->next;
    }
    return head;
}
int main()
{
    while (true)
    {
        int t, num;
        ListNode *head, *p, *q;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cin >> t;
            if (i == 0)
            {
                head = new ListNode(t);
                q = head;
            }
            else
            {
                p = new ListNode(t);
                q->next = p;
                q = p;
            }
        }
        head = insertionSortList(head);
        p = head;
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
}