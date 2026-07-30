class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gascost =0, toatalcost = 0;
        for(auto itr : gas)
            gascost += itr;
        for(auto itr : cost)
            toatalcost += itr;
        if(toatalcost > gascost)
            return -1;

        vector<int> diff = vector<int>(gas.size());
        for(int i = 0; i < diff.size(); i++)
        {
            diff[i] = gas[i] - cost[i];
        }
        int ret = 0, totaldiff = diff[0];
        for(int i = 1; i < diff.size(); i++)
        {
            if(totaldiff < 0)
            {
                ret = i;
                totaldiff = diff[i];
            }
            else
            {
                totaldiff += diff[i];
            }
        }
        if(totaldiff < 0)
            return -1;
        return ret;
        
    }
};
