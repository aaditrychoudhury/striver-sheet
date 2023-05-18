//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //1.create an adjacency list
        vector<int> adj[N];
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //2.create an distance array
        vector<int> dist(N,INT_MAX);
        //3.create an queue storing node,weight
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                //if the new distance is less then push the node with the updated 
                //dist in the queue
                if(dist[it]> dist[node]+1) {
                    dist[it] = dist[node] +1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<N;++i) if(dist[i] == INT_MAX) dist[i] = -1;
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
