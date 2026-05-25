class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy = nums;
        vector<int> ret;
        sort(copy.begin(), copy.end());
        for(int i =0, j = copy.size()-1; i != j;)
        {
            if(copy[i] + copy[j] == target)
            {
                for(int k = 0; k < nums.size();k++)
                {
                    if(nums[k] == copy[i] || nums[k] == copy[j])
                    {
                        ret.push_back(k);
                        if(ret.size() == 2)
                            return ret;
                    }
                }
            }
            else if (copy[i] + copy[j] > target)
            {
                j--;
            }
            else 
            {
                i++;
            }
        }
        return ret;
        
    }
};
