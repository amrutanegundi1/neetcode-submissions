class Solution {
public:
    vector<string> res;
    string curr;
    vector<string> generateParenthesis(int n) {

        backtrack(0, 0, n);
        return res;
        
    }

    void backtrack(int open, int close, int n)
    {
        if(open == close && open == n)
        {
            res.push_back(curr);
            return;
        }

        if(open < n)
        {
            curr += "(";
            backtrack(open+1, close, n);
            curr = curr.substr(0, curr.length()-1);
        }
        if(close < open)
        {
            curr += ")";
            backtrack(open, close+1, n);
            curr = curr.substr(0, curr.length()-1);
        }
    }
};
