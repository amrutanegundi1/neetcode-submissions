class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> watcher;
        for( auto itr : nums) {
            if(watcher.find(itr) != watcher.end())
            {
                return true;
            }
            watcher.insert(itr);
        }
        return false;
    }
};