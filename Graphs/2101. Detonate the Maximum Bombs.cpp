class Solution {
    private:
    void dfs(int node,vector<int> adj[],int &dist,vector<int> &vis){
        //vec.push_back(node);
        vis[node] = 1;
        dist++;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,dist,vis);
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;++i){
            long long int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j=0;j<n;++j){
                if(i!=j){
                    long long int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                    long long int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                    if(dist <= r1*r1) adj[i].push_back(j);
                }
            }
        }

        //int vis[n] = {0};
        int ans =0;
        for(int i=0;i<n;++i){
            int dist=0;
            vector<int> vis(n,0);
           dfs(i,adj,dist,vis);
            ans = max(ans , dist);
        }
        return ans;
    }
};
