class MinStack {
    stack<int> st;
    stack<int> minSt;
    int min = INT_MAX;

   public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (val <= min) {
            minSt.push(val);
            min = val;
        }
    }

    void pop() {
        int top = st.top();
        st.pop();
        if (top == minSt.top()) {
            minSt.pop();
            if(!minSt.empty())
                min = minSt.top();
            else
                min = INT_MAX;
        }
    }

    int top() { return st.top(); }

    int getMin() { return min; }
};
