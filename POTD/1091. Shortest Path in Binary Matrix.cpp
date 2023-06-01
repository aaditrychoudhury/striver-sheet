class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0] == 1) return -1;
        if(n==1) return 1;
        q.push({1,{0,0}});
        dist[0][0] = 1;
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it = q.front();
            int d = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            for(int i=0;i<8;++i){
                int newr = row+dr[i];
                int newc = col+dc[i];
                if(newr<n && newr>=0 && newc<n && newc>=0 && 
                grid[newr][newc]== 0 && d+1<dist[newr][newc]){
                    dist[newr][newc] = d+1;
                    if(newr == n-1 && newc == n-1) return dist[n-1][n-1];
                    q.push({dist[newr][newc],{newr,newc}});
                }
            }

        }
        return -1;
    }
};
