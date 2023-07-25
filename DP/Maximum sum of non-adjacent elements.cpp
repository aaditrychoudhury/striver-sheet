//recurion 
#include <bits/stdc++.h> 
int solve(vector<int> &nums,int ind){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    int pick = nums[ind] + solve(nums,ind-2);
    int nonPick = 0 + solve(nums,ind-1);
    return max(pick,nonPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    return solve(nums,n-1);
}
//memoization
#include <bits/stdc++.h> 
int solve(vector<int> &nums,vector<int> &dp,int ind){
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int pick = nums[ind] + solve(nums,dp,ind-2);
    int notPick = 0 + solve(nums,dp,ind-1);
    return dp[ind] = max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve(nums,dp,n-1);
}
//tabulation 
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    for(int i=1;i<n;++i){
        int pick = nums[i];
        if(i > 1) pick+= dp[i-2];
        int notpick = 0 + dp[i-1];
        dp[i] = max(pick,notpick);
    }
    return dp[n-1];
}
//space optimization
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    int curri;
    for(int i=1;i<n;++i){
        int pick = nums[i];
        if(i > 1) pick+= prev2;
        int notpick = 0 + prev;
        curri = max(pick,notpick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
