class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;


        for(int i = 0; i <= k; i++)
        {
            vector<int> temp = prices;

            for(auto itr : flights)
            {
                int src = itr[0], dst = itr[1], price = itr[2];

                if(prices[src] != INT_MAX)
                {
                    if(temp[dst] > prices[src] + price)
                    {
                        temp[dst] = prices[src] + price;
                    }
                }
            }
            prices = temp;
        }
        if(prices[dst] == INT_MAX)
            return -1;
        return prices[dst];
    }
};
