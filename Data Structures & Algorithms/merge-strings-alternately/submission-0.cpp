class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = 0, l2 = 0;
        int s1 = word1.length(), s2 = word2.length();
        string res;
        while(l1 < s1 && l2 < s2)
        {
            res += word1[l1++];
            res += word2[l2++];        
        }
        if(s1 < s2)
        {
            cout<<l1<<" "<<word2.substr(l1)<<endl;
            res += word2.substr(l1);
        }
        else if(s2 < s1)
        {
            res += word1.substr(l2);
        }
        return res;
    }
};