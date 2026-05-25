class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int product = 1;
        int non_zero_product = 1;
        for (auto itr : nums) {
            product *= itr;
        }
        if (product == 0) {
            int count = 0;
            for (auto itr : nums) {
                if (itr != 0) {
                    non_zero_product *= itr;
                } else {
                    count++;
                }
            }
            if(count > 1)
            {
                non_zero_product = 0;
            }
        }
        int i = 0;
        for (auto itr : nums) {
            if (itr != 0) {
                result.push_back(product / itr);
            } else {
                result.push_back(non_zero_product);
            }
        }
        return result;
    }
};
