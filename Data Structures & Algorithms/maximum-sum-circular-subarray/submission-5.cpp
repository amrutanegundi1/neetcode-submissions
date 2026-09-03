class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalmin = nums[0], globalmax = nums[0], currmin = 0, currmax = 0, total = 0;

        for(auto itr : nums)
        {
            currmax += itr;
            currmax = max(itr, currmax);
            globalmax = max(globalmax, currmax);
            currmin += itr;
            currmin = min(itr, currmin);
            globalmin = min(globalmin, currmin);
            total += itr;
        }
        if(globalmax < 0)
        {
            return globalmax;
        }
        return max(globalmax, total - globalmin);
    }
};