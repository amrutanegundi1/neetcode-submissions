class TrieNode
{
    public:
        TrieNode* children[26];
        bool endOfWord;
    public:
        TrieNode()
        {
            for(int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
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
            if(temp->children[word[i] - 'a'] == nullptr)
            {
                temp->children[word[i] - 'a'] = new TrieNode();
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for( int i = 0; i < word.length(); i++)
        {
            if(temp->children[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[word[i] - 'a'];
        }
        return (temp->endOfWord == true);
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for( int i = 0; i < prefix.length(); i++)
        {
            if(temp->children[prefix[i] - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[prefix[i] - 'a'];
        }
        return true;
    }
};
