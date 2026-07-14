class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        // sort(hand.begin(), hand.end());
        // int itr = hand.size() / groupSize;
        // int k = 0;
        // for (int i = 0; i < itr; i++) {
        //     int start = -1;
        //     k = 0;
        //     for (int j = 0; j < hand.size() && k < groupSize; j++) {
        //         if (hand[j] == -1) continue;
        //         if (start == -1) {
        //             start = hand[j];
        //             hand[j] = -1;
        //             k++;
        //         } else if (hand[j] == start) {
        //             continue;
        //         } else if (hand[j] > start + 1) {
        //             return false;
        //         } else {
        //             start = hand[j];
        //             hand[j] = -1;
        //             k++;
        //         }
        //     }
        // }
        // if (k == groupSize) return true;
        // return false;
        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> que;
        for(auto itr : hand)
        {
            
            mp[itr]++;
            if(mp[itr] == 1)
            {
                que.push(itr);
            }
        }

        int noOfItr = hand.size()/groupSize;

        for(int i = 0; i < noOfItr; i++)
        {
            int start = que.top();
            while(mp[start] == 0 && !que.empty())
            {
                que.pop();
                start = que.top();
            }
            if(que.empty())
            {
                cout<<"que is empty"<<endl;
                return false;
            }
            mp[start]--;
            cout<<start<<" ";
            int currSize = 1;
            while(currSize < groupSize)
            {
                if(mp.find(start+1) == mp.end() || mp[start+1] == 0)
                {
                    cout<<start+1<<endl;
                    return false;
                }
                mp[start + 1]--;
                currSize++;
                cout<<start + 1<<" ";
                start = start + 1;
            }
        }
        return true;

    }
};
