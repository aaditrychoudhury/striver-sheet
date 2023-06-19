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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            root = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            mp[hd][lvl].insert(root->val);
            if(root->left) q.push({root->left,{hd-1,lvl+1}});
           if(root->right) q.push({root->right,{hd+1,lvl+1}}); 
        }
        for(auto p : mp){
            vector<int> temp;
            for(auto q: p.second){
                
                for(auto r: q.second) temp.push_back(r);
            }
            //sort(temp.begin(),temp.end());
             ans.push_back(temp);
        }
        return ans;
    }
};
