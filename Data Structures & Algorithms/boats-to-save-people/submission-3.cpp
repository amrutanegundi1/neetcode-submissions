class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        int l = 0, r = people.size()-1, boat = 0;
        while(l <= r)
        {
            int rem = limit-people[r];
            if(rem >= people[l])
            {
                l++;
            }
            r--;
            boat++;
        } 
        return boat;
    }
};