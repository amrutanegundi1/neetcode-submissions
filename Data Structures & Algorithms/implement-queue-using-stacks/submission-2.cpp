class MyQueue {
   public:
    stack<int> s1, s2;
    int top;
    bool init;
    MyQueue() { init = false; }

    void push(int x) {
        s1.push(x);
        if (!init) {
            top = x;
            init = true;
        }
    }

    int pop() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int top1 = s2.top();
        s2.pop();
        init = false;
        while (!s2.empty()) {
            if (!init) {
                init = true;
                top = s2.top();
            }
            s1.push(s2.top());
            s2.pop();
        }
        return top1;
    }

    int peek() { return top; }

    bool empty() { return s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */