class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for(auto itr : strs)
        {
            encoded_str += to_string(itr.size()) + ",";
        }
        encoded_str += "#";
        for(auto itr : strs)
        {
            encoded_str += itr;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> result;
        if(s.length() > 0)
        {
            int i= 0;
            vector<int> sizes;
            while(s[i] != '#')
            {
                string size = "";
                while(s[i] != ',')
                {
                    size += s[i++];
                }
                i++;
                sizes.push_back(atoi(size.c_str()));
            }
            i++;
            for(auto itr : sizes)
            {
                result.push_back(s.substr(i, itr));
                i += itr;
            }
        }
        return result;
    }
};
