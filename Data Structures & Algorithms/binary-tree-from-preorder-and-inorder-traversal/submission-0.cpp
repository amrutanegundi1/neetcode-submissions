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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = nullptr;
        if(preorder.empty() || inorder.empty())
            return nullptr;
        
        int mid = findMiddle(preorder, inorder);
        res = new TreeNode(preorder[0]);
        vector<int> newLeftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> newRightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> newLeftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> newRightIn(inorder.begin() + mid+1, inorder.end());

        res->left = buildTree(newLeftPre,newLeftIn);
        res->right = buildTree(newRightPre,newRightIn);

        return res;
    }

    int findMiddle(vector<int>& preorder, vector<int>& inorder)
    {
        for(int i = 0; i< inorder.size(); i++)
        {
            if(inorder[i] == preorder[0])
                return i;
        }
        return -1;
    }
};
