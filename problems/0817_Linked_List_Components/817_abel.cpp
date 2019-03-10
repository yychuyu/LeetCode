/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
解题思路：开辟一个足够大的数组map存储G数组的值，令map[G[i]] = G[i]，每访问一个链表结点可以直接根据map中的值判断是否属于G数组，不需要反复遍历。
 */
class Solution { 
    public: int numComponents(ListNode* head, vector<int>& G) { 
        int map[10000]; 
        int count = 0, flag = 0; //count 块数
        for (int i = 0; i < 10000; i++) { 
            map[i] = -1; 
        } 
        for (int j = 0; j < G.size(); j++) { 
            map[G[j]] = G[j]; 
        } 
        ListNode* p = head; 
        while(p) 
        { 
            if (map[p->val] != -1) //判定当前节点是否为G中值
            { 
                flag = 1; 
                if (p->next == NULL)//最后节点
                    count++;
            } 
            else 
            { 
                if (flag == 1) 
                { 
                    count++;//判定上一个块的flag值
                    flag = 0; 
                } 
            } 
            p = p->next; 
        } 
        return count; 
    } 
};
