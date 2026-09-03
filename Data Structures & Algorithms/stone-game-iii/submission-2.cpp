class Solution {
public:
    map<pair<int, bool>, int> mp; 
    string stoneGameIII(vector<int>& stoneValue) {
        int alicesum = dfs(stoneValue, 0, true);
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int bobsum = total - alicesum;
        cout<<alicesum<<" "<<total<<" "<<bobsum<<endl;
        if(alicesum > bobsum)
        {
            return "Alice";
        }
        else if(alicesum < bobsum)
        {
            return "Bob";
        }
        return "Tie";
    }

    int dfs(vector<int>& stoneValue, int i, bool alice)
    {
        if(i >= stoneValue.size())
        {
            return 0;
        }
        if(mp.find({i, alice}) != mp.end())
        {
            return mp[{i, alice}];
        }
        int res = INT_MIN;
        if(!alice)
        {
            res = INT_MAX;
        }
        for(int j = 0; j < 3; j++)
        {
            int sum = 0;
            
            for(int k = 0; k <= j; k++)
            {
                if(i + k >= stoneValue.size())
                {
                    break;
                }
                sum += stoneValue[i + k];
                //cout<<sum<<endl;
            }

            if(alice)
            {
                res = max(res, sum + dfs(stoneValue, i + j + 1, !alice));
            }
            else
            {
                res = min(res, dfs(stoneValue, i + j + 1, !alice));
            }
        }
        mp[{i, alice}] = res;
        return res;
    }
};