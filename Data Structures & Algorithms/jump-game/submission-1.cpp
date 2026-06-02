class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<bool> res(nums.size());
        res[0] = true;

        for(int i = 0; i < nums.size(); i++)
        {
            if(res[i])
            {
                for (int j = i + 1; j - i <= nums[i]; j++)
                {
                    if(j >= nums.size())
                        break;
                    res[j] = true;
                }
            }
        }
        return res[nums.size()-1];
    }
};
