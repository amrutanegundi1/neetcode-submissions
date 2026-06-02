class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = nums[0], curr = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(curr < 0)
                curr = 0;
            curr += nums[i];
            res = max(res, curr);
            cout << curr << " "<< res<<endl;
        }
        return res;

    }
};
