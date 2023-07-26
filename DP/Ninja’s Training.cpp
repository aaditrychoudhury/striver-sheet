int f(int day,vector<vector<int>> &points,int lastTask,vector<vector<int>> &dp){
    if(day == 0){
        int maxi=0;
        for(int i=0;i<3;++i){
            if(i != lastTask)
                maxi = max(maxi,points[0][i]);
        }
        return dp[day][lastTask] = maxi;
    }
    if(dp[day][lastTask] != -1) return dp[day][lastTask];
    int maxi =0 ;
    for(int i=0;i<3;++i){
        if(i != lastTask){
            //phale + aaj
            int point = points[day][i] + f(day-1,points,i,dp);
            maxi = max(maxi , point);
        }
    }
    return dp[day][lastTask] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return f(n-1,points,3,dp);
    // Write your code here.
}
