class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        unordered_map<int, int> mp;
        priority_queue<int> que;
        int boat = 0;
        for (auto itr : people) {
            mp[itr]++;
            que.push(itr);
        }
        while (mp.size() > 0) {
            int n1;
            do {
                n1 = que.top();
                que.pop();
            } while (!que.empty() && mp.find(n1) == mp.end());
            mp[n1]--;
            cout << n1 << " " << mp[n1] << endl;
            if (mp[n1] == 0) {
                mp.erase(n1);
            }

            for (int i = limit - n1; i > 0; i--) {
                if (mp.find(i) != mp.end()) {
                    mp[i]--;
                    cout << i << " " << mp[i] << endl;
                    if (mp[i] == 0) {
                        mp.erase(i);
                    }
                    break;
                }
            }
            boat++;
        }
        return boat;
    }
};