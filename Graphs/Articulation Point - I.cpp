//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int timer=1;
    void dfs(int node,int parent,vector<int>adj[],vector<int> &vis,int time[],int low[],
    vector<int> &mark){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        int child=0;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,adj,vis,time,low,mark);
                low[node] = min(low[it],low[node]);
                if(low[it] >= time[node] && parent!=-1){
                    mark[node] = 1;
                }
                ++child;
            }else{
                low[node] = min(low[node], time[it]);
            }
            
        }
        if(child>1 && parent == -1) mark[node] = 1;
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> vis(n,0);
        int time[n];
        int low[n];
        vector<int> mark(n,0);
        for(int i=0;i<n;++i){
            if(!vis[i])
                dfs(i,-1,adj,vis,time,low,mark);
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(mark[i] == 1)ans.push_back(i);
        }
        if(ans.size()==0) return{-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
