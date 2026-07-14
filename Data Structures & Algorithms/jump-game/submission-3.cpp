class Solution {
public:
    bool canJump(vector<int>& nums) {

        // int maxReachable = 0;

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(maxReachable>= i)
        //     {
        //         maxReachable = max(maxReachable, i + nums[i]);
        //     }
        // }
        
        // return maxReachable >= nums.size()-1;

        vector<bool> res(nums.size(), false);
        res[nums.size()-1] = true;

        for(int i = nums.size()-2; i >= 0; i--)
        {
            if(i + nums[i] >= nums.size()-1)
            {
                res[i] = true;
            }
            else if(nums[i] == 0)
            {
                res[i] = false;
            }
            else
            {
                for(int j = i + 1; j <= i + nums[i]; j++)
                {
                    if(res[j] == true)
                    {
                        res[i] = true;
                        break;
                    }
                }
            }
        }
        return res[0];
    }
};
