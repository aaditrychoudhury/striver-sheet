//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Disjoint{
    public:
    vector<int> parent,size;
    Disjoint(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int val){
        if(parent[val] == val) return val;
        return parent[val] = find(parent[val]);
    }
    void unionBySize(int u,int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        Disjoint ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt =0;
        vector<int> ans;
        
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int i=0;i<4;++i){
                int adjr = row+dr[i];
                int adjc = col+dc[i];
                if(adjr<n && adjr>=0 && adjc<m && adjc>=0 && vis[adjr][adjc] == 1){
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if(ds.find(nodeNo) != ds.find(adjNodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
