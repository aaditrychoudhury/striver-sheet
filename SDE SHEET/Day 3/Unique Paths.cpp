class Solution {
    private:
    int solve(int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i>= m || j>=n) return 0;
        if(i==(m-1) && j==(n-1)) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int opt1 = solve(m,n,i+1,j,dp);
        int opt2 = solve(m,n,i,j+1,dp);
        return dp[i][j] = opt1+opt2;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int num =  solve(m,n,0,0,dp);
        if(m==1&&n==1) return num;
        return dp[0][0];
    }
};
