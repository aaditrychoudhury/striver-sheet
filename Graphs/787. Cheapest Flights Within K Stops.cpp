class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        int l = flights.size();
        for(int i=0;i<l;++i) adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        int stops =0;
        q.push({stops,{src,dist[src]}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int d = it.second.second;
            if(stop<=k){
                for(auto it: adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    if(d+wt < dist[v]){
                        dist[v] = d+wt;
                        q.push({stop+1,{v,dist[v]}});
                    }
                }
            }
            
        }
        if(dist[dst] != 1e9) return dist[dst];
        return -1;
    }
};
