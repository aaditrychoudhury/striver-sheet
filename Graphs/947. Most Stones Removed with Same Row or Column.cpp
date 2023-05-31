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
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int n = stones.size();
        int maxcol = 0;
        for(auto it : stones){
            maxrow = max(maxrow , it[0]);
            maxcol = max(maxcol, it[1]);
        }
        Disjoint ds(maxrow+maxcol+1);
        unordered_map<int,int> nodeCnt;
        //linking together row and col of each stone;
        for(auto it: stones){
            int noder = it[0];
            int nodec = it[1] + maxrow+1;
            ds.unionBySize(noder,nodec);
            nodeCnt[noder] = 1;
            nodeCnt[nodec] = 1;
        }
        //finding the ultimate parent
        int cnt=0;
        for(auto it: nodeCnt){
            if(ds.find(it.first) == it.first) ++cnt;
        }
        return n-cnt;
    }
};
