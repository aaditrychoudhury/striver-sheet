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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        q.push(NULL);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root == NULL){
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
            else{
                temp.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
