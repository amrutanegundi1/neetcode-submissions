/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }

    Node* dfs(vector<vector<int>>& grid, int n, int t, int l)
    {
        bool allSame = true;

        for(int i = t; i < t + n; i++)
        {
            for(int j = l; j < l + n; j++)
            {
                if(grid[t][l] != grid[i][j])
                {
                    allSame = false;
                    break;
                }
            }
        }
       
        if(allSame)
        {
            return new Node(grid[t][l], true);
        }

        n = n/2;

        Node* topLeft = dfs(grid,n,t,l);
        Node* topRight = dfs(grid,n,t,l +n);
        Node* bottomLeft = dfs(grid,n,t+n,l);
        Node* bottomRight = dfs(grid,n,t+n,l +n);

        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};