class Solution {
private:
    void solve(int n,int k,int start,vector<int> &temp,vector<vector<int>> &ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=n;++i){
            temp.push_back(i);
            solve(n,k,i+1,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,k,1,temp,ans);
        return ans;
    }
};
