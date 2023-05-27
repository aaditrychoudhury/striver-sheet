class Disjoint{
    public:
    vector<int> size, parent;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;++i){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int val){
        if(parent[val] == val) return val;
        return parent[val] = find(parent[val]);
    }
    void unionBySize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int extraedges =0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.find(u) == ds.find(v)) ++extraedges;
            else ds.unionBySize(u,v);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(ds.parent[i] == i) ++ans;
        }
        --ans;
        if(extraedges >= ans) return ans;
        return -1;
    }
};
