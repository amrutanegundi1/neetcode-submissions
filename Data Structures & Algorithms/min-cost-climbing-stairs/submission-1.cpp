class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), INT_MAX);
        int m1 = cost[0];
        int m2 = cost[1];
        for(int i =2; i< cost.size(); i++)
        {
            int temp = cost[i] + min(m1, m2);
            m1 = m2;
            m2 = temp;
        }
        return min(m1, m2);
    }
};
