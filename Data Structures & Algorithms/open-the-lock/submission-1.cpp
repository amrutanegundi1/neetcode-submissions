class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> block(deadends.begin(), deadends.end());
        if (block.find("0000") != block.end()) return -1;
        queue<pair<string, int>> que;
        que.push({"0000", 0});
        unordered_set<string> visited;
        while (!que.empty()) {
            pair<string, int> pr = que.front();
            que.pop();
            if (pr.first == target) {
                return pr.second;
            }
            if (block.find(pr.first) == block.end()) {
                vector<string> comb = findAllComb(pr.first);
                for (auto itr : comb) {
                    if(visited.find(itr) == visited.end())
                    {
                        visited.insert(itr);
                        que.push({itr, pr.second +1});
                    }
                }
            }
        }
        return -1;
    }
    vector<string> findAllComb(string s)
    {
        vector<string> res;
        for(int i = 0; i < 4; i++)
        {
            string tar = s;
            tar[i] = ((s[i] - '0' + 1) % 10) + '0'; 
            res.emplace_back(tar);
            tar = s;
            tar[i] = ((s[i] - '0' - 1 + 10) % 10) + '0'; 
            res.emplace_back(tar);
        }
        return res;
    }
};