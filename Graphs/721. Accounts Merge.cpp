class Disjoint{
    vector<int> size, parent;
    public:
    Disjoint (int n){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        //first part of merging the mail of common emails;
        unordered_map<string,int> mapMailNode;
        for(int i=0;i<n;++i){
            for(int j=1;j<accounts[i].size();++j){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()) mapMailNode[mail] = i;
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        //second part storing all the mails with same ultimate parent together in the arrays of vector
        vector<string> mergedMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.find(it.second);
            mergedMail[node].push_back(mail);
        }

        //third part is the storing the sorted mail with there name
        vector<vector<string>> ans;
        for(int i=0;i<n;++i){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
