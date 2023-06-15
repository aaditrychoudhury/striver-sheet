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
    int maxLevelSum(TreeNode* root) {
        int maxiSum =INT_MIN;
        int maxiStep= 1;
        int step= 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
             ++step;
            for(int i=0;i<size;++i){
                root = q.front();
                q.pop();
                sum += root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            if(sum > maxiSum){
                maxiSum = sum;
                maxiStep = step;
            }
           
        }
        return maxiStep;
    }
};
