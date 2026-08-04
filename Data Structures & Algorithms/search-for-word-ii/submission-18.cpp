class Trie {
   public:
    unordered_map<char, Trie*> children;
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
        void addWord(string s)
        {
            Trie* temp = root;
            for(auto itr : s)
            {
                if(temp->children.find(itr) == temp->children.end())
                {
                    temp->children[itr] = new Trie();
                }
                temp = temp->children[itr];
            }
            temp->endOfWord = true;
        }


};
class Solution {
   public:
    set<string> res;
    string curr;
    vector<vector<bool>> visited;
    int rows, cols;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree tree;
        rows = board.size();
        cols = board[0].size();
        visited.resize(board.size(), vector<bool>(board[0].size(), false));
        for(auto itr : words)
        {   
            tree.addWord(itr);
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, tree.root);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>>& board, int i, int j, Trie* root)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols)
        {
            return;
        }

        if(visited[i][j] == true || root->children.find(board[i][j]) == root->children.end())
        {
            return;
        }
        visited[i][j] = true;
        curr += board[i][j];
        root = root->children[board[i][j]];
        if(root->endOfWord)
        {
            res.insert(curr);
        }
        dfs(board, i+1, j, root);
        dfs(board, i-1, j, root);
        dfs(board, i, j + 1, root);
        dfs(board, i, j - 1, root);
        visited[i][j] = false;
        curr.pop_back();
    }
};
