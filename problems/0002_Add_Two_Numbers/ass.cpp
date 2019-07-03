// LeetCode 第二题 "Add two numbers"
//linklist's simple usage
//g++ for WSL(ubuntu)
class Solution {
    public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
	int carry = 0; //进位标志，若两数相加
	ListNode* sum = new ListNode(0); //默认初始化为0
	ListNode* ptr = sum;             //ptr point to sum
	while(l1 != NULL || l2 != NULL)
	{
            int val1=0;
            int val2=0;
            if(l1 !=NULL)
	         {
                    val1=l1->val;   //read value of linked list 1
                    l1=l1->next;
             }
		 if(l2 != NULL)
		 {
		 val2 = l2->val; //……
		 l2 = l2->next;
		 }
		 int tmp = val1 + val2 + carry;
		 ptr->next = new ListNode(tmp % 10); //防止发生数值相加之后的溢出，采用mod运算
		 carry = tmp / 10; //若有进位则保存至carry位
		 ptr = ptr->next; //next bit
    }
	if(carry == 1) // 发生溢出需要进位，且调用构造函数初始化为1
	{
                ptr->next =new ListNode(1);
    }
        return sum->next; //return sum
	
	}
};
