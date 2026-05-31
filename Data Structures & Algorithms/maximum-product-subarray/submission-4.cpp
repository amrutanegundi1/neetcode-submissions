class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMax = 1, currMin = 1;

        for(int i =0; i < nums.size(); i++)
        {
            cout<<currMax<<" "<<currMin<<endl;
            int temp = currMax*nums[i];
            currMax = max(currMax*nums[i], max(currMin*nums[i], nums[i]));
            
            currMin = min(currMin*nums[i], min(temp, nums[i]));
            res = max(res, currMax);
            cout<<currMax<<" "<<currMin<<endl;
        } 
        return res;
        
    }
};
