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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;
            for(int i =0 ;i<size;i++)
            {
                TreeNode* a = q.front();
                q.pop();
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
                temp.push_back(a->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
