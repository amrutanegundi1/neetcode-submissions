class Solution {
public:
    vector<string> res;
    string curr;
    unordered_map<int, vector<char>> mp;
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return vector<string>({});
        mp.insert({'2', vector<char>({'a','b','c'})});
        mp.insert({'3', vector<char>({'d','e','f'})});
        mp.insert({'4', vector<char>({'g','h','i'})});
        mp.insert({'5', vector<char>({'j','k','l'})});
        mp.insert({'6', vector<char>({'m','n','o'})});
        mp.insert({'7', vector<char>({'p','q','r', 's'})});
        mp.insert({'8', vector<char>({'t','u','v'})});
        mp.insert({'9', vector<char>({'w','x','y','z'})});


        dfs(digits, 0);
        return res;
        
    }

    void dfs(string digits, int i)
    {
        if(i == digits.length())
        {
            res.push_back(curr);
            return;
        }

        for(int j = 0; j < mp[digits[i]].size(); j++)
        {
            curr+= mp[digits[i]][j];
            dfs(digits, i+1);
            curr = curr.substr(0, curr.length()-1);
        }
    }

};
