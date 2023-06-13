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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        dfs(root,diameter);
        return diameter;
    }
private:
    int dfs(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int lh = dfs(root->left,maxi);
        int rh = dfs(root->right,maxi);
        maxi = max(rh+lh,maxi);
        return 1 + max(lh,rh);
    }
};
