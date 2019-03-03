package stack.easy;

import java.util.LinkedList;

public class ImplementStackUsingQueues {
    private LinkedList<Integer> queue;
    /** Initialize your data structure here. */
    public ImplementStackUsingQueues() {
        this.queue = new LinkedList<>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        queue.add(x);
        if (!queue.isEmpty()) {
            for (int i = 0;i < queue.size() - 1;i++){
                queue.add(queue.pop());
            }
        }

    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return queue.pop();
    }

    /** Get the top element. */
    public int top() {
        return queue.element();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return queue.isEmpty();
    }
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */