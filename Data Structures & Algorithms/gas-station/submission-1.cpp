class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int n = gas.size();
        // for(int i = 0; i < gas.size(); i++)
        // {
        //     int startpos = i, endpos = i, res = i;
        //     int nogas = false;
        //     int curr = 0;
        //     do
        //     {
        //         curr += gas[startpos];
        //         if(curr >= cost[startpos])
        //         {
        //             curr = curr - cost[startpos];
        //             startpos = (startpos + 1)% n;
        //         }
        //         else
        //         {
        //             nogas = true;
        //         }

        //     }while(startpos != endpos && nogas == false);
        //     if(!nogas)
        //     {
        //         return res;
        //     }
        // }
        // return -1;
        int gasSum = 0, costSum = 0;
        for(auto itr : gas)
            gasSum += itr;
        for(auto itr : cost)
            costSum += itr; 
        if(gasSum < costSum)
            return -1;
        int total = 0, start = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            total += gas[i] - cost[i];
            if(total < 0)
            {
                total = 0;
                start = i + 1;
            }
        }
        return start;
        
    }
};
