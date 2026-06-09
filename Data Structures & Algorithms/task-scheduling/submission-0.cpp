class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (auto itr : tasks) {
            if (mp.find(itr) != mp.end()) {
                mp[itr]++;
            } else {
                mp[itr] = 1;
            }
        }
        priority_queue<int> que;
        for (auto itr : mp) {
            que.push(itr.second);
        }
        int cyc = 0;
        while (!que.empty()) {
            vector<int> vc;
            for (int i = 0; i <= n; i++) {
                if (!que.empty()) {
                    int tp = que.top();
                    que.pop();
                    if (tp - 1 > 0) {
                        vc.push_back(tp - 1);
                    }
                    cyc++;
                } else if (que.empty() && vc.size() == 0) {
                    break;
                } else {
                    cyc++;
                }
            }
            if (vc.size() > 0) {
                for (auto itr : vc) {
                    que.push(itr);
                }
            }
        }
        return cyc;
    }
};
