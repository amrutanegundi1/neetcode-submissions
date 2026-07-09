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
    int res = INT_MIN;
    int kthSmallest(TreeNode* root, int k) {
         morrisTravesal(root,k);
         return res;
    }

    void morrisTravesal(TreeNode* root1, int &k)
    {
        if(!root1)
        {
            return;
        }
        morrisTravesal(root1->left, k);
        k--;
        if(k == 0)
        {
            cout<<root1->val<<" ";
            res = root1->val;
        }
        morrisTravesal(root1->right, k);

    }
};
