class Solution {
public:
    bool isValid(string s) {
        stack<char> braces;
        for(auto ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
                braces.push(ch);
            else if(ch == ')')
            {
                if(!braces.empty() && braces.top() == '(')
                {
                    braces.pop();
                } 
                else 
                {
                    return false;
                }
            }
            else if(ch == '}')
            {
                if(!braces.empty() && braces.top() == '{')
                {
                    braces.pop();
                } 
                else 
                {
                    return false;
                }
            }
            else if(ch == ']')
            {
                if(!braces.empty() && braces.top() == '[')
                {
                    braces.pop();
                } 
                else 
                {
                    return false;
                }
            }
        }

        return braces.empty();
    }
};
