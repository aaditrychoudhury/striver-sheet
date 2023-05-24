class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto road: roads) {
            adj[road[0]].push_back({road[1] , road[2]});
            adj[road[1]].push_back({road[0] , road[2]});
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, 
        greater<pair<long long,long long>>> q;
        vector<long long> ways(n,0);
        vector<long long> dist(n,LONG_MAX);
        ways[0] = 1;
        dist[0] =0;
        q.push({0,0});
        long long mod = (long long) (1e9 + 7);
        while(!q.empty()){
            auto it = q.top();
            long long d = it.first;
            long long node = it.second;
            q.pop();
            for(auto i: adj[node]){
                long long v = i.first;
                long long wt = i.second;
                if(d+wt < dist[v]){
                    dist[v] = d+wt;
                    q.push({dist[v],v});
                    ways[v] = ways[node];
                }else if(d+wt == dist[v]) ways[v] = (ways[v] + ways[node]) % mod;
            }
        }
        //if(ways[n-1] == 1e9) return -1;
        return ways[n-1]%mod;
    }
};
