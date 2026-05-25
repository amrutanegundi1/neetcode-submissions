/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if(root == nullptr)
        //     return 0;
        // return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
        if(root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while(!que.empty())
        {
            int nodes = que.size();
            for(int i = 0; i < nodes; i++)
            {
                TreeNode* curr = que.front();
                que.pop();
                if(curr->left)
                    que.push(curr->left);
                if(curr->right)
                    que.push(curr->right);
            }
            level++;
        }
        return level;
    }
};
