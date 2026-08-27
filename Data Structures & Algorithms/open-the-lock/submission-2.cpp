class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> block(deadends.begin(), deadends.end());
        if (block.find("0000") != block.end()) return -1;
        queue<string> que;
        que.push("0000");
        unordered_set<string> visited;
        int steps = 0;
        while (!que.empty()) {
            for (int i = que.size(); i > 0; i--) {
                string pr = que.front();
                que.pop();
                if (pr == target) {
                    return steps;
                }
                if (block.find(pr) == block.end()) {
                    vector<string> comb = findAllComb(pr);
                    for (auto itr : comb) {
                        if (visited.find(itr) == visited.end()) {
                            visited.insert(itr);
                            que.push(itr);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    vector<string> findAllComb(string s) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
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