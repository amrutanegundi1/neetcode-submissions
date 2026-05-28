class TrieNode
{
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord;
    public:
        TrieNode()
        {
            endOfWord = false;
        }
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for( int i = 0; i < word.length(); i++)
        {
            if(temp->children[word[i]] == nullptr)
            {
                temp->children[word[i]] = new TrieNode();
            }
            temp = temp->children[word[i]];
        }
        temp->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for( int i = 0; i < word.length(); i++)
        {
            if(temp->children[word[i]] == nullptr)
            {
                return false;
            }
            temp = temp->children[word[i]];
        }
        return (temp->endOfWord == true);
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for( int i = 0; i < prefix.length(); i++)
        {
            if(temp->children[prefix[i]] == nullptr)
            {
                return false;
            }
            temp = temp->children[prefix[i]];
        }
        return true;
    }
};
