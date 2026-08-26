class TrieNode
{
    public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void addWord(string s)
    {
        TrieNode *temp = root;

        for(auto itr : s)
        {
            if(temp->children.find(itr) == temp->children.end())
            {
                temp->children[itr] = new TrieNode();
            }
            temp = temp->children[itr];
        }
        temp->endOfWord = true;
    }
};
class Solution {
public:
    string curr;
    vector<string> res;
    Trie t;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto itr : wordDict)
        {
            t.addWord(itr);
        }
        dfs(s, 0, "", t.root);
        return res;
    }
    void dfs(string s, int i, string c, TrieNode* r)
    {
        if(i == s.length() && r->endOfWord == true)
        {
            res.push_back(c);
            return;
        }
        if(i == s.length())
        {
            return;
        }
        if(r->children.find(s[i]) == r->children.end())
        {
            return;
        }
        r = r->children[s[i]];
        c += s[i];
        if(r->endOfWord)
        {
            c += " ";
            dfs(s, i + 1, c, t.root);
            c.pop_back();
        }
        dfs(s, i + 1, c, r);

    }
};