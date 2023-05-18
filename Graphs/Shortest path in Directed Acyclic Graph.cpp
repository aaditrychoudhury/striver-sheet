//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
  void dfs_topo(int node, vector<int>& vis, stack<int>& st, vector<pair<int, int>> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
      int i = it.first;
      if (!vis[i]) {
        dfs_topo(i, vis, st, adj);
      }
    }
    st.push(node);
  }

public:
  vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[N];
    for (auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];
      adj[u].push_back({v, wt});
    }

    vector<int> vis(N, 0);
    stack<int> st;
    for (int i = 0; i < N; ++i) {
      if (!vis[i]) {
        dfs_topo(i, vis, st, adj);
      }
    }

    // dist
    vector<int> dist(N, 1e9);
    dist[0] = 0;
    while (!st.empty()) {
      int node = st.top();
      st.pop();
      for (auto it : adj[node]) {
        int v = it.first;
        int wt = it.second;
        if (dist[node] + wt < dist[v]) {
          dist[v] = dist[node] + wt;
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      if (dist[i] == 1e9) {
        dist[i] = -1;
      }
    }

    return dist;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
