class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;//assign weights for both the directions
        }
        //Floyd Warshall Algorithm
        for(int via =0;via<n;++via){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(i==j) dist[i][j] = 0;
                    else if(dist[i][via] + dist[via][j] < dist[i][j]){
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }
        //checking the city 
        int city =-1;
        int countmax = n;
        for(int i=0;i<n;++i){
            int cnt=0;
            for(int j=0;j<n;++j){
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(countmax > cnt){
                countmax = cnt;
                city = i;
            }else if(countmax == cnt){
                city = max(city,i);
            }
        }
        return city;
    }
};
