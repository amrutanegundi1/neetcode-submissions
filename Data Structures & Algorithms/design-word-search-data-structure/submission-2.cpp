class TrieNode
{
    public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};
class WordDictionary {
    TrieNode * root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *temp = root;
        for(int i = 0; i < word.length(); i++)
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
        queue<TrieNode*> nodesToSearch;
        
        nodesToSearch.push(root);
       
        for(int i = 0; i < word.length(); i++)
        {
            if(word[i] == '.')
            {
                for(int j = nodesToSearch.size()-1; j >= 0; j--)
                {
                    TrieNode *curr = nodesToSearch.front();
                    nodesToSearch.pop();
                    for(auto itr : curr->children)
                    {
                        nodesToSearch.push(itr.second);
                    }
                }
            }
            else 
            {
                for(int j = nodesToSearch.size()-1; j >= 0; j--)
                {
                    TrieNode *curr = nodesToSearch.front();
                    nodesToSearch.pop();
                    if(curr->children.find(word[i]) != curr->children.end())
                    {
                        nodesToSearch.push(curr->children[word[i]]);
                    }
                }
            }
            if(nodesToSearch.size() == 0)
            {
                break;
            }
        }
        if(nodesToSearch.size() > 0)
        {
            TrieNode *curr = nodesToSearch.front();
            nodesToSearch.pop();
            if(curr->endOfWord)
            {
                return true;
            }
        }
        return false;
     }

     bool dfs(string word, TrieNode* root, int ind)
     {
        TrieNode* curr = root;
        for(int i = ind; i < word.length(); i++)
        {
            if(word[i] == '.')
            {
                for(auto itr : curr->children)
                {
                    if(dfs(word, itr.second, i +1))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if(curr->children.find(word[i]) == curr->children.end())
                {
                    return false;
                }
                curr = curr->children[word[i]];
            }
        }
        return curr->endOfWord;
     }
};
