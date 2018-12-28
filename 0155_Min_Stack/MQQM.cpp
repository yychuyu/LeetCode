/*
  题目：
  设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
  
  push(x) -- 将元素 x 推入栈中。
  pop() -- 删除栈顶的元素。
  top() -- 获取栈顶元素。
  getMin() -- 检索栈中的最小元素。
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if( min_stk.empty() ){
            min_stk.push(x);
        }else{
            if( min_stk.top() > x ){
                min_stk.push(x);
            }else{
                min_stk.push(min_stk.top());
            }
        }
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
private:
    stack<int> stk;
    stack<int> min_stk;    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
