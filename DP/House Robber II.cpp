#include <bits/stdc++.h> 
long long int solve(vector<long long int> &nums){
    long long int prev = nums[0];
    long long int prev2=0,curri;
    for(long long int i=0;i<nums.size();++i){
        long long int pick = nums[i];
        if(i>1) pick+= prev2;
        long long int nonpick = 0+prev;
        curri = max(pick,nonpick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<long long int> temp1,temp2;
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(long long int i=0;i<n;++i){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=(n-1)) temp2.push_back(valueInHouse[i]);
    }
    return max(solve(temp1),solve(temp2));
}
