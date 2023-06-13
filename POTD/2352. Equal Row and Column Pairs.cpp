class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        int cnt =0;
        int n = grid.size();
        for(int i=0;i<n;++i){
            vector<int> temp;
            for(int j=0;j<n;++j) temp.push_back(grid[i][j]);
            //if(mp.find(temp) != mp.end()) cnt++;
            mp[temp]++;
        }
        for(int j=0;j<n;++j){
            vector<int> temp;
            for(int i=0;i<n;++i) temp.push_back(grid[i][j]);
            //if(mp.find(temp) != mp.end()) {
               cnt+=mp[temp];
            //}
            //mp[temp]++;
        }
    return cnt;
    }
};
