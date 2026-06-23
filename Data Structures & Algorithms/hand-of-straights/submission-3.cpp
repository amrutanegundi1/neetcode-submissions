class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        int itr = hand.size() / groupSize;
        int k = 0;
        for (int i = 0; i < itr; i++) {
            int start = -1;
            k = 0;
            for (int j = 0; j < hand.size() && k < groupSize; j++) {
                if (hand[j] == -1) continue;
                if (start == -1) {
                    start = hand[j];
                    hand[j] = -1;
                    k++;
                } else if (hand[j] == start) {
                    continue;
                } else if (hand[j] > start + 1) {
                    return false;
                } else {
                    start = hand[j];
                    hand[j] = -1;
                    k++;
                }
            }
        }
        if (k == groupSize) return true;
        return false;
    }
};
