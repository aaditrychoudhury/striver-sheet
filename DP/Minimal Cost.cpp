//recursion
int solve(int index,int k,vector<int> &height){
    if(index == 0) return 0;
    int mini = INT_MAX;
    for(int i=1;i<=k;++i){
        if(index-i >=0){
            int jump = solve(index-i,k,height) + abs(height[i] - height[i-k]);
            mini = min(mini,jump);
        }
    }
    return mini;
}

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    return solve(n,k,height);
}
//memoization
int solve(int index,int k,vector<int> &height,vector<int> &dp){
    if(index == 0) return 0;
    if(dp[index] != -1) return dp[index];
    dp[index] = INT_MAX;
    for(int i=1;i<=k;++i){
        if(index-i >=0){
            int jump = solve(index-i,k,height,dp) + abs(height[i] - height[i-k]);
            dp[index] = min(dp[index],jump);
        }
    }
    return dp[index];
}

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,-1);
    return solve(n,k,height,dp);
}
//Tabulation

#include <bits/stdc++.h>
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n,0);
    // return solve(n,k,height,dp);
    dp[0] = 0;
    for(int i=1;i<n;++i){
        int mini = INT_MAX;
        for(int j=1;j<=k;++j){
            if(i-j >=0){
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                mini = min(mini,jump);
            }
        }
        dp[i] = mini;
    }
    return dp[n-1];
}
