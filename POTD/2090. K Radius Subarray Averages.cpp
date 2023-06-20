class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        int l=0,r=0;
        long long int sum = 0;
        while(r<n){
            sum+= nums[r];
            if(r-l+1 == (2*k +1)){
                ans[r-k] = sum / (2*k+1);
                sum -= nums[l];
                ++l;
            }
            ++r;
        }
        return ans;
    }
};
