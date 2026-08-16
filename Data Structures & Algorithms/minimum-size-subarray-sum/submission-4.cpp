class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, currSum = 0, res = INT_MAX;
        while (r < nums.size()) {
            
            currSum += nums[r];
            if (currSum < target) {
                r++;
            } else {
                
                while (currSum >= target) {
                    res = min(res, r - l + 1);
                    currSum -= nums[l];
                    l++;
                }
                r++;
            }
        }
        if (res == INT_MAX) {
            return 0;
        }
        return res;
    }
};