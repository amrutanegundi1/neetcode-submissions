class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;

        for (auto itr : hand) {
            mp[itr]++;
        }
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(),hand.end());
        for (int i = 0; i < hand.size(); i++) {
            if (mp.size() != 0 && mp.find(hand[i]) != mp.end()) {
                int counter = 0;
                int start = hand[i]-1;
                cout<<"start from"<<hand[i]<<endl;
                while (counter < groupSize) {
                    
                    start++;
                    cout<<start<<endl;
                    if(mp.find(start) == mp.end())
                    {
                        return false;
                    }
                    mp[start]--;
                    if (mp[start] == 0) mp.erase(start);
                    counter++;
                }
            }
        }
        return true;
    }
};
