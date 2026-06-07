class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);

        for(int i =0; i < temperatures.size(); i++)
        {
            for(int j = i+1; j < temperatures.size(); j++)
            {
                if(temperatures[j] > temperatures[i])
                {
                    results[i] = j -i;
                    break;
                }
            }
        }
        return results;
    }
};
