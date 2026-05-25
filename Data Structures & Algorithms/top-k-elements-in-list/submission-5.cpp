struct Customcomp
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first < b.first;
        }
    };
class Solution {
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        for(int i = 0; i<nums.size();i++)
        {
            counter[nums[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Customcomp> heap;
        for (auto& entry : counter) {
            heap.push(pair<int,int>(entry.second, entry.first));
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
