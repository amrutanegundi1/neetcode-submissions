class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        array<int, 2> counter({0, 0});
        for(auto itr : bills)
        {
            switch(itr)
            {
                case 5:
                    counter[0]++;
                    break;
                case 10:
                    if(counter[0] > 0)
                    {
                        counter[0]--;
                        counter[1]++;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case 20:
                    if(counter[1] > 0 && counter[0] > 0)
                    {
                        counter[0]--;
                        counter[1]--;
                    }
                    else if(counter[0] >= 3)
                    {
                        counter[0] -= 3;
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
};