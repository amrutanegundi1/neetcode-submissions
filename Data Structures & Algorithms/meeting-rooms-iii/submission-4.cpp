struct Comp {
   public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

class Solution {
   public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> res(n, 0);
        vector<bool> avail(n, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> que;
        // for (int i = 0; i < n; i++) {
        //     que.push({meetings[i][1] - 1, i});
        //     res[i]++;
        //     avail[i] = false;
        //     cout << meetings[i][1] - 1 << " " << i << " "
        //              << res[i]<< endl;
        // }
        int counter = n;
        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            while (!que.empty() && que.top().first < start) {
                avail[que.top().second] = true;
                que.pop();
                counter++;
            }
            //cout<<i<<" counter "<<counter<<endl;
            if (counter > 0) {
                for (int k = 0; k < n; k++) {
                    if (avail[k]) {
                        counter--;
                        res[k]++;
                        que.push({meetings[i][1] - 1, k});
                        avail[k] = false;
                    //     //cout << meetings[i][1] - 1 << " " << k << " "
                    //  << res[k]<<" "<<counter<< endl;
                        break;
                    }
                }
            } else {
                pair<int, int> tp = que.top();
                que.pop();
                res[tp.second]++;
                que.push({tp.first + 1 + (meetings[i][1] - meetings[i][0]) - 1, tp.second});
                // //cout << (tp.first + 1 + (meetings[i][1] - meetings[i][0]) - 1) << " " << tp.second << " "
                //      << res[tp.second]<< endl;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout<<i<<" "<<res[i]<<endl;
        // }
        int result = res[0], room = 0;
        for (int i = 1; i < n; i++) {
            if (res[i] > result) {
                result = res[i];
                room = i;
            }
        }
        return room;
    }
};