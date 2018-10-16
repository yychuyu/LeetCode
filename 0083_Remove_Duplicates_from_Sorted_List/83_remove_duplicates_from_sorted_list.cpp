/**
* LeetCode The 83th problem :remove-duplicates-from-sorted-list
* Auth:Barlowwang
* Date:2018-10-08
**/ 
class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *prev = head->next, *current = head;
        while (prev != NULL)
        {
            if (prev->val == current->val)
            {
                current->next = prev->next;
                delete prev;
                prev = current->next;
            }
            else
            {
                current = current->next;
                prev = prev->next;
            }
        }
        return head;
    }
};