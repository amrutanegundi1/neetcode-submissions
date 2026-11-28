class Solution {
public:
    map<pair<int,int>, int> mp;
    int uniquePaths(int m, int n) {

        return dfs(0,0,m,n);
    }
    int dfs(int i, int j, int m, int n)
    {
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        if(i >=m || j >= n)
        {
            return 0;
        }
        if(mp.find({i,j}) != mp.end())
        {
            return mp[{i,j}];
        }
        mp[{i,j}] = dfs(i+1,j,m,n) + dfs(i, j+1,m,n);
        return mp[{i,j}];
    }


};
