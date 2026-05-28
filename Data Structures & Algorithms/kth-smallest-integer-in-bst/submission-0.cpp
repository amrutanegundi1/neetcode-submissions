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
    int kthSmallest(TreeNode* root, int k) {

        vector<int> data;
        preOrder(root,data);
        return data[k-1];
    }

    void preOrder(TreeNode* root, vector<int> &data)
    {
        if(!root)
            return;
        
        preOrder(root->left,data);
        data.push_back(root->val);
        preOrder(root->right, data);
    }
};
