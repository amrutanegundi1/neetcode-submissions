class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, currSum = 0, res = INT_MAX;
        while (r < nums.size() && l <= r) {
            
            currSum += nums[r];
            if (currSum < target) {
                r++;
            } else {
                res = min(res, r - l + 1);
                while (currSum >= target) {
                    currSum -= nums[l];
                    l++;
                    if(currSum >= target)
                    {
                        res = min(res, r - l + 1);
                        cout<<currSum<<" "<<l<<" "<<r<<" "<<res<<endl;
                    }
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