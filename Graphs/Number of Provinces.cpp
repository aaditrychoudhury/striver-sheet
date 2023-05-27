//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Disjoint{
    vector<int> size,parent;
  public:
  
  Disjoint(int n){
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<=n;++i){
          parent[i] = i;
          size[i]=1;
      }
  }
  int find(int X){
      if(parent[X] == X) return X;
      return parent[X] = find(parent[X]);
  }
  void unionBySize(int u,int v){
      int ulp_u = find(u);
      int ulp_v = find(v);
      if(ulp_u == ulp_v) return;
      if(size[ulp_u] < size[ulp_v]){
          parent[ulp_u] = ulp_v;
          size[ulp_v] += ulp_u;
      }else{
          parent[ulp_v] = ulp_u;
          size[ulp_u] += ulp_v;
      }
  }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        Disjoint ds(V);
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j){
                if(adj[i][j] == 1) ds.unionBySize(i,j);
            }
        }
        int cnt =0;
        for(int i=0;i<V;++i){
            if(ds.find(i) == i) ++cnt;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
