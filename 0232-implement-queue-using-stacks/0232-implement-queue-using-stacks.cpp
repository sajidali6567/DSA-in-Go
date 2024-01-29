class MyQueue {
public:
    // first stack will be used to push element
    stack<int> firstStack;
    // second stack will be used to pop element and find the front element
    stack<int> secondStack;
    
    MyQueue() {
    }
    
    void push(int x) {
        firstStack.push(x);
    }
    
    int pop() {
        if(secondStack.empty()) {
            moveFirstStackElementIntoSecond();
        }
        int ans = secondStack.top();
        secondStack.pop();
        return ans;
    }
    
    int peek() {
        if(secondStack.empty()) {
            moveFirstStackElementIntoSecond();
        }
        return secondStack.top();
    }
    
    bool empty() {
        return firstStack.empty() && secondStack.empty();
    }
    
    void moveFirstStackElementIntoSecond() {
        // copy all the element from the firstStack to secondStack
        while(!firstStack.empty()) {
            secondStack.push(firstStack.top());
            firstStack.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */