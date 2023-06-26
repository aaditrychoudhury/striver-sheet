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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int ans =0;
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int first,last;
            for(int i=0;i<size;++i){
                long long int cur_id = q.front().second - mini;
                root = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i == size-1) last = cur_id;
                if(root->left != NULL) q.push({root->left,cur_id*2});
                if(root->right != NULL) q.push({root->right,cur_id*2+1});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};
