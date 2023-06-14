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
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int val = -1;
        dfs(root,val,mini);
        return mini;
    }
private:
    void dfs(TreeNode* root,int &val,int &mini){
        if(root->left) dfs(root->left,val,mini);
        if(val != -1) mini = min(mini, abs(root->val - val));
        val = root->val;
        if(root->right) dfs(root->right,val,mini);
        //return mini;
    }
};
