class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int size = nums.size();
        int res = INT_MIN;
        for (int start = 0; start < nums.size(); start++) {
            int currSum = INT_MIN;
            int count = 0;
            while (count < size) {
                if (currSum == INT_MIN) {
                    currSum = nums[((start + count) % size)];
                } else {
                    currSum += nums[((start + count) % size)];
                }
                res = max(res, currSum);
                if (currSum < 0) currSum = INT_MIN;
                count++;
            }
        }
        return res;
    }
};