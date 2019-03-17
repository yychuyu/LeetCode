# 第817题，链表，easy，C++


# 思路：用指针p表示当前链表结点，p一开始为head头结点，
# 我们从G中挨个遍历，如果能找到，说明p的val在G中存在，
# 这时，把p后移一个，即p=p->next，
# 再在G（从G[0]到G[n-1]）中找p的值，
# 如果找到，同样进行行操作，直到在中找不到p->val为止。
# 此时，组件的个数加1。
# Links：https://blog.csdn.net/qq_36327328/article/details/83315978 

/**** 结果：
Runtime: 380 ms, faster than 5.05% of C++ online submissions for Linked List Components.
Memory Usage: 13 MB, less than 98.51% of C++ online submissions for Linked List Components.

***/



class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head||G.empty())  return 0;
        int num=0;//记录组件个数
        ListNode* p=head;
        while(p){
            int t=0;
            for(int i=0;i<G.size();i++){
                if(G[i]==p->val) {//G中找到了p->val
                    p=p->next;//p后移一个
                    i=-1;//G从头开始找p->val的值
                    t++;//记录一个组件的长度 
                    if(!p) break; 
                }
            }
            if(t) {num++;}//continue;}//组件长度不为0,组件个数加1
            if(!p) break; 
            p=p->next;
        }
        return num;
    }
};




# 完整调试代码如下
/***
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head||G.empty())  return 0;
        int num=0;//记录组件个数
        ListNode* p=head;
        while(p){
            int t=0;
            for(int i=0;i<G.size();i++){
                if(G[i]==p->val) {//G中找到了p->val
                    p=p->next;//p后移一个
                    i=-1;//G从头开始找p->val的值
                    t++;//记录一个组件的长度 
                    if(!p) break; 
                }
            }
            if(t) {num++;}//continue;}//组件长度不为0,组件个数加1
            if(!p) break; 
            p=p->next;
        }
        return num;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        vector<int> G = stringToIntegerVector(line);
        
        int ret = Solution().numComponents(head, G);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}


***/

