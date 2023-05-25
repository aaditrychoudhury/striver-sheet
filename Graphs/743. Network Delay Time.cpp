class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> time(n+1,INT_MAX);
        time[k] = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(t+wt < time[v]){
                    time[v] = t+wt;
                    pq.push({time[v],v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;++i){
            if(time[i] == INT_MAX) return -1;
            ans = max(ans,time[i]);
        }
        return ans;
    }
};
