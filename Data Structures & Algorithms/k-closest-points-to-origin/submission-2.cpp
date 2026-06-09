class Solution {
    static bool comp(vector<int> a, vector<int> b) {
        double d1 = sqrt((a[0] * a[0] + a[1] * a[1]));
        double d2 = sqrt((b[0] * b[0] + b[1] * b[1]));

        return (d1 < d2);
    }

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
