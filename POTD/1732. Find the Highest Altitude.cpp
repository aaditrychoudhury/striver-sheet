class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans[n+1];
        ans[0] = 0;
        for(int i=0;i<n;++i){
            ans[i+1] = ans[i] + gain[i];
        }
        int maxi = INT_MIN;
        for(int i=0;i<n+1;++i){
            if(maxi < ans[i]) maxi = ans[i];
        }
        return maxi;
    }
};
