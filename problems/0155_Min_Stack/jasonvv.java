class MinStack {
    LinkedList<Integer> dataStack;
    LinkedList<Integer> minStack;
    /** initialize your data structure here. */
    public MinStack() {
        dataStack = new LinkedList<Integer>();
        minStack = new LinkedList<Integer>();
    }
    
    public void push(int x) {
        dataStack.push(x);
        if(minStack.isEmpty() || x < minStack.peek()) {
            minStack.push(x);
        } else {
            minStack.push(minStack.peek());
        }
    }
    
    public void pop() {
        if(!dataStack.isEmpty()) {
            dataStack.pop();
            minStack.pop();
        }
    }
    
    public int top() {
        return dataStack.peek();
    }
    
    public int getMin() {
        return minStack.peek();
    }
}
