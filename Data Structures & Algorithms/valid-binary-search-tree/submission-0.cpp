class Solution {
    void inorder(TreeNode* root, vector<int>& res)
    {
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i - 1]) return false;
        }
        return true;
    }
};