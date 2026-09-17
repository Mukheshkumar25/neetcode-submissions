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
    int solve(int &maxi,TreeNode* root)
    {
        if(!root)return 0;
        int left = solve(maxi,root->left);
        int right = solve(maxi,root->right);
        int maxh = max(left,right);
        maxi = max(maxi ,maxh + 1);
        return 1 + maxh;
    }
    int maxDepth(TreeNode* root) {
        int maxi = 0;
        solve(maxi,root);
        return maxi;
    }
};
