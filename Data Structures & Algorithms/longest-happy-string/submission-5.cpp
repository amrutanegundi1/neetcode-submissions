class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        priority_queue<pair<int, char>> que;
        if (a > 0) {
            que.push({a, 'a'});
        }
        if (b > 0) {
            que.push({b, 'b'});
        }
        if (c > 0) {
            que.push({c, 'c'});
        }
        while (!que.empty()) {
            pair<int, char> pr = que.top();
            que.pop();
            cout<<pr.first<<" "<<pr.second<<endl;
            if(result[result.length()-1] == pr.second && result[result.length()-2]  == pr.second)
            {
                if(que.empty())
                {
                    break;
                }
                pair<int, char> pr2 = que.top();
                que.pop();
                result += pr2.second;
                if(pr2.first > 1)
                {
                    que.push({pr2.first-1, pr2.second});
                }
                if(pr.first > 1)
                    que.push({pr.first, pr.second});
            }
            else
            {
                result += pr.second;
                if(pr.first > 1)
                    que.push({pr.first-1, pr.second});
            }
            
        }
        return result;
    }
};