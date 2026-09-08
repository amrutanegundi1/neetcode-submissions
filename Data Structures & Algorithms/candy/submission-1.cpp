class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> can(ratings.size(), 1);

        for(int i = 1; i < can.size(); i++)
        {
            if(ratings[i] > ratings[i-1])
            {

                can[i] = can[i-1] + 1;
                // cout<<i<<" first "<<can[i]<<endl;
            }
        }

        for(int i = can.size()-2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {

                if(can[i] <= can[i+1])
                {
                    can[i] = can[i+1] + 1;
                    // cout<<i<<" second "<<can[i]<<endl;

                }
            }
        }

        return accumulate(can.begin(), can.end(), 0);
    }
};