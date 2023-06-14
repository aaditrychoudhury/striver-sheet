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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        int flag =0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n>0){
                root = q.front();
                q.pop();
                --n;
                if(root != NULL) temp.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(flag == 1) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};
