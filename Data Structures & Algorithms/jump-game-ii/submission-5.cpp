class Solution {
public:
    int jump(vector<int>& nums) {

        // vector<int> dp(nums.size(), INT_MAX);

        // dp[nums.size()-1] = 0;
        // for(int i = nums.size()-2; i >= 0; i--)
        // {
        //     int j = nums[i];
        //     if(j != 0)
        //     {
        //         int minimum = INT_MAX;
        //         for(int k = i + 1, c = 0; k < nums.size() && c < j; k++,c++)
        //         {
        //             if(dp[k] < minimum)
        //             {
        //                 minimum = dp[k];
        //             }
        //         }
        //         dp[i] = minimum + 1;
        //     }
        // }
        // return dp[0];

        // int res = 0;

        // int l = 0, r = 0;
        // while(r < nums.size()-1)
        // {
        //     int farthest = 0;
        //     for(int i =l; i<= r; i++)
        //     {
        //         farthest = max(farthest, i + nums[i]);
        //     }
        //     l = r+1;
        //     r = farthest;
        //     res+=1;
        // }
        // return res;


        int res = 0; 
        int l = 0, r = 0;
        int farthest = 0;
        while(r < nums.size()-1)
        {
            for(int i = l; i <= r; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
        
    }
};
