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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        string result = "";

        for(auto itr : res)
        {
            result += itr;
            result += ",";
        }
        //cout<<res.size()<<" "<<result<<endl;
        return result;
    }

    void dfsSerialize(TreeNode * root, vector<string> &res)
    {
        if(!root)
        {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vec;
        int pos = -1;

        int curr = 0;

        while((pos = data.find(",", pos+1)) != string::npos)
        {
            int num = INT_MIN;
            if(data.substr(curr, pos -curr) != "N")
            {
                num = std::stoi(data.substr(curr, pos));
            }
            curr = pos + 1; 
            vec.push_back(num);
        }
        int i = 0;
        TreeNode* root = construct(vec, i);
        return root;
    }
    TreeNode* construct(vector<int>& vec, int& i)
    {
        if(vec[i] == INT_MIN)
        {
            i++;
            return nullptr;
        }

        TreeNode *root = new TreeNode(vec[i]);
        i++;
        root->left = construct(vec, i);
        root->right = construct(vec, i);
        return root;
    }
};
