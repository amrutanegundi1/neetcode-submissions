class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        set<int> st;
        for (auto itr : nums)
        {
            st.insert(itr);
        }

        int maxLength = 0;

        for(auto itr : nums)
        {
            if(st.find(itr - 1) == st.end())
            {
                // this is the start of the LC
                int cur = 0;
                int next = itr;
                while(1)
                {
                    cur++;
                    next += 1; 
                    if(st.find(next) == st.end())
                    {
                        break;
                    }
                }
                maxLength = max(cur, maxLength);
            }
        }        
        return maxLength;
    }
};
