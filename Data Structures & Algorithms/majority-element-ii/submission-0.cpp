class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

        for(auto itr : nums)
        {
            if(itr == num1)
            {
                cnt1++;
            }
            else if(itr == num2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                num1 = itr;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                num2 = itr;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(auto itr : nums)
        {
            if(itr == num1)
            {
                cnt1++;
            }
            else if(itr == num2)
            {
                cnt2++;
            }
        }

        vector<int> result;
        if(cnt1 > nums.size()/3)
        {
            result.push_back(num1);
        }
        if(cnt2 > nums.size()/3)
        {
            result.push_back(num2);
        }
        return result;
    }
};