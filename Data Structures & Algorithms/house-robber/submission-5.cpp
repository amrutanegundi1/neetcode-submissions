class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        vector<int> result(nums.size()+1, 0);

        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++)
        {
            result[i] = max(nums[i] + result[i-2], result[i-1]);
        }

        return result[nums.size()-1];
    }

    int robRecursive(vector<int>& nums, int ind)
    {
        if(ind >= nums.size() || ind < 0)
            return 0;

        int n1 = robRecursive(nums, ind+2);
        int n2 = robRecursive(nums, ind+1);

        return max(nums[ind] + n1, n2);
    }
};
