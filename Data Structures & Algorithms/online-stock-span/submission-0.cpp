class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);
        int i = prices.size()-1;
        while(i >= 0 && prices[i] <= price)
        {
                i--;
        }
        cout<<prices.size()<<" "<<i<<endl;
        return prices.size() -i-1;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */