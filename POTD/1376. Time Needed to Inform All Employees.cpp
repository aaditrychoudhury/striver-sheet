class Solution {
    private:
    void dfs(int manager,vector<int> adj[],vector<int>& informTime, int &ans,int &mx){
        mx = max(ans,mx);
        for(auto employee : adj[manager]){
            ans += informTime[manager];
            dfs(employee,adj,informTime,ans,mx);
            ans -= informTime[manager];
        }
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1) return 0;
        vector<int> adj[n];
        for(int i=0;i<n;++i){
            int val = manager[i];
            if(val != -1) adj[val].push_back(i);
        }
        int ans=0;
        int mx =0;
        dfs(headID,adj,informTime,ans,mx);
        return mx;
    }
};
