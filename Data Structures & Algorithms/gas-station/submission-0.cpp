class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < gas.size(); i++)
        {
            int startpos = i, endpos = i, res = i;
            int nogas = false;
            int curr = 0;
            do
            {
                curr += gas[startpos];
                if(curr >= cost[startpos])
                {
                    curr = curr - cost[startpos];
                    startpos = (startpos + 1)% n;
                }
                else
                {
                    nogas = true;
                }

            }while(startpos != endpos && nogas == false);
            if(!nogas)
            {
                return res;
            }
        }
        return -1;
        
    }
};
