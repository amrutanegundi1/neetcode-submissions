class TrieNode
{
    public:
    bool endOfWord;
    unordered_map<char, TrieNode*> children;
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        for(auto itr : word)
        {
            if(temp->children.find(itr) == temp->children.end())
            {
                temp->children[itr] = new TrieNode();
            }
            temp = temp->children[itr];
        }
        temp->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for(auto itr : word)
        {
            if(temp->children.find(itr) == temp->children.end())
            {
                return false;
            }
            temp = temp->children[itr];
        }
        return (temp->endOfWord == true);
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(auto itr : prefix)
        {
            if(temp->children.find(itr) == temp->children.end())
            {
                return false;
            }
            temp = temp->children[itr];
        }
        return true;
    }
};
