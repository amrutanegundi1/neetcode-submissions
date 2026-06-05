class Trie
{
public:
    unordered_map<char, Trie*> child;
    bool endOfWord;
};

class PrefixTree
{
public:
    Trie* root;
    PrefixTree()
    {
        root = new Trie();
    }

    void addWord(string word)
    {
        Trie *temp = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(temp->child.find(word[i]) == temp->child.end())
            {
                temp->child[word[i]] = new Trie();
            }
            temp = temp->child[word[i]];
        }
        temp->endOfWord = true;
    }

    bool prefix(string word)
    {
        Trie *temp = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(temp->child.find(word[i]) == temp->child.end())
            {
                return false;
            }
            temp = temp->child[word[i]];
        }
        return true;
    }

    bool searchWord(string word)
    {
        Trie *temp = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(temp->child.find(word[i]) == temp->child.end())
            {
                return false;
            }
            temp = temp->child[word[i]];
        }
        return (temp->endOfWord == true);
    }
};

class Solution {
public:
    PrefixTree prefixTree;
    set<string> result;
    set<pair<int, int>> visited;
    int ROWS, COLS;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i = 0; i < words.size(); i++)
        {
            prefixTree.addWord(words[i]);
        }
        ROWS = board.size();
        COLS = board[0].size();

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                string curr = "";
                visited.clear();
                dfs(board, prefixTree.root, i, j, curr);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
    void dfs(vector<vector<char>>& board, Trie* node, int r, int c, string& curr)
    {
        if(r < 0 || r>= ROWS || c < 0 || c >= COLS)
        {
            return;
        }
        pair<int, int> pr(r,c);
        if(visited.find(pr) != visited.end() || node->child.find(board[r][c]) == node->child.end())
        {
            return;
        }

        visited.insert(pr);
        node = node->child[board[r][c]];
        curr += board[r][c];
        if(node->endOfWord)
        {
            result.insert(curr);
        }
        dfs(board, node, r+1, c, curr);
        dfs(board, node, r-1, c, curr);
        dfs(board, node, r, c+1, curr);
        dfs(board, node, r, c-1, curr);
        visited.erase(pr);
        curr = curr.substr(0, curr.length()-1);
    }
};
