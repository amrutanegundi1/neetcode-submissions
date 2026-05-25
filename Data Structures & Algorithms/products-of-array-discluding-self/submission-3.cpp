class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product_non_zero = 1;
        int zeroCount = 0;
        for(auto itr : nums)
        {
            if(itr != 0)
            {
                product_non_zero *= itr;
            }
            else
            {
                zeroCount++;
            }
        }
        if(zeroCount > 1)
        {
            return vector<int>(nums.size(), 0);
        }
        vector<int> result;
        for(auto itr : nums)
        {
            if(itr == 0)
            {
                result.push_back(product_non_zero);
            }
            else if(zeroCount == 1)
            {
                result.push_back(0);
            }
            else
            {
                result.push_back(product_non_zero/itr);
            }
        }
        return result;
    }
};
