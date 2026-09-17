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
    int maxi  = -1001;
public:
    int solve(TreeNode* root)
    {
        if(!root)return 0;
        int left = solve(root->left);
        left = max(left,0);
        int right = solve(root->right);
        right = max(right,0);
        maxi = max(maxi,left + root->val);
        maxi = max(maxi,right + root->val);
        maxi = max(maxi,left + right + root->val);
        return max(left,right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }

};
