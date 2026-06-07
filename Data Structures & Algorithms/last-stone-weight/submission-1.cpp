class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        
        while (size > 1) {
            sort(stones.begin(), stones.end());
            int s1 = stones[stones.size() - 1];
            int s2 = stones[stones.size() - 2];
            if (s1 == s2) {
                size -= 2;
                stones.pop_back();
                stones.pop_back();
            } else {
                size -= 1;
                stones[stones.size() - 1] = 0;
                stones[stones.size() - 2] = abs(s1 - s2);
                stones.pop_back();
            }
        }
        if (size == 0) {
            return 0;
        }
        
        return stones[0];
    }
};
