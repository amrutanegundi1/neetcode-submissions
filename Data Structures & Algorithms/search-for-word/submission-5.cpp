class Solution {
    set<pair<int, int>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {

        for(int i =0; i < board.size(); i++)
        {
            for(int j =0; j < board[0].size(); j++)
            {
                if(check(board, word, i, j, 0))
                {
                    return true;
                }
                
            }
        }
        return false;
    }

    bool check(vector<vector<char>>& board, string word, int row, int col, int ind)
    {
        // cout<<row<<" "<<col<<" "<<ind<<endl;
        if(row >= board.size() || col >= board[0].size() || row < 0 || col < 0)
        {
            return false;
        }
        pair<int,int> node(row,col);
        if(board[row][col] != word[ind] || visited.find(node) != visited.end())
        {
            return false;
        }
        if(ind == word.size()-1)
        {
            return true;
        }
        
        visited.insert(node);
        bool ret = check(board, word, row, col+1,ind+1) || check(board, word, row+1, col,ind+1) || check(board, word, row, col-1,ind+1) || check(board, word, row-1, col,ind+1);
        visited.erase(node);
        return ret;
    }
};
