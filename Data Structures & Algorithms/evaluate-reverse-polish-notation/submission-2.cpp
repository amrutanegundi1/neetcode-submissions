class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int res = stoi(tokens[0]);
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                res = n1 + n2;
                st.push(to_string(res));
            } else if (tokens[i] == "-") {
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                res = n2 - n1;
                st.push(to_string(res));
            } else if (tokens[i] == "*") {
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                res = n1 * n2;
                st.push(to_string(res));
            } else if (tokens[i] == "/") {
                int n1 = stoi(st.top());
                st.pop();
                int n2 = stoi(st.top());
                st.pop();
                res = n2 / n1;
                st.push(to_string(res));
            } else
                st.push(tokens[i]);
        }
        return res;
    }
};
