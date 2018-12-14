/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, int> originmap;
        vector<RandomListNode *> newmap;
        int count = 0;
        RandomListNode *tmpptr = head;
        while(tmpptr){
            newmap.push_back(new RandomListNode(tmpptr->label));
            originmap[tmpptr]=count;
            tmpptr = tmpptr->next;
            count ++;
        }
        newmap.push_back(nullptr);
        tmpptr = head;
        count = 0;
        int randomIndex = 0;
        while(tmpptr){
            if(tmpptr->random){
                randomIndex = originmap[tmpptr->random];
                newmap[count]->random = newmap[randomIndex];
            }
            newmap[count]->next = newmap[count+1];
            tmpptr = tmpptr->next;
            count++;
        }
        return newmap[0];
    }
};