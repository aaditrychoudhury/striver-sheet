//Memoization
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}

//Tabulation method 
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,0);
    //return solve(n-1,heights,dp);
    dp[0] = 0;
    for(int i=1;i<n;++i){
        int fs = dp[i-1] + abs( heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1)  ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}
//space optimization
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,0);
    //return solve(n-1,heights,dp);
    int prev = 0,prev2 =0;
    for(int i=1;i<n;++i){
        int fs = prev + abs( heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i>1)  ss = prev2 + abs(heights[i] - heights[i-2]);
        int curr = min(fs,ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
