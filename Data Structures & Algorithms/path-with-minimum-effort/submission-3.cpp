class Solution {
   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int res = INT_MAX;
        int dstRow = heights.size() - 1, dstCol = heights[0].size() - 1;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> que;
        que.push({0, {0, 0}});
        vector<vector<int>> dist;
        dist.resize(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        dist[0][0] = 0;

        while (!que.empty()) {
            auto tp = que.top();
            que.pop();
            if (tp.second.first == dstRow && tp.second.second == dstCol) {
                return tp.first;
            }
            if (tp.second.first + 1 <= dstRow) {
                int newHeight = max(tp.first,
                                    abs(heights[tp.second.first][tp.second.second] -
                                        heights[tp.second.first + 1][tp.second.second]));
                int oldEffort = dist[tp.second.first + 1][tp.second.second];
                if (newHeight < oldEffort) {
                    dist[tp.second.first + 1][tp.second.second] = newHeight;
                    que.push({newHeight, {tp.second.first + 1, tp.second.second}});
                }
            }
            if (tp.second.first - 1 >= 0) {
                int newHeight = max(tp.first,
                                    abs(heights[tp.second.first][tp.second.second] -
                                        heights[tp.second.first - 1][tp.second.second]));
                int oldEffort = dist[tp.second.first - 1][tp.second.second];
                if (newHeight < oldEffort) {
                    dist[tp.second.first - 1][tp.second.second] = newHeight;
                    que.push({newHeight, {tp.second.first - 1, tp.second.second}});
                }
            }
            if (tp.second.second + 1 <= dstCol) {
                int newHeight = max(tp.first,
                                    abs(heights[tp.second.first][tp.second.second] -
                                        heights[tp.second.first][tp.second.second + 1]));
                int oldEffort = dist[tp.second.first][tp.second.second + 1];
                if (newHeight < oldEffort) {
                    dist[tp.second.first][tp.second.second + 1] = newHeight;
                    que.push({newHeight, {tp.second.first, tp.second.second + 1}});
                }
            }
            if (tp.second.second - 1 >= 0) {
                int newHeight = max(tp.first,
                                    abs(heights[tp.second.first][tp.second.second] -
                                        heights[tp.second.first][tp.second.second - 1]));
                int oldEffort = dist[tp.second.first][tp.second.second - 1];
                if (newHeight < oldEffort) {
                    dist[tp.second.first][tp.second.second - 1] = newHeight;
                    que.push({newHeight, {tp.second.first, tp.second.second - 1}});
                }
            }
        }
        return res;
    }
};