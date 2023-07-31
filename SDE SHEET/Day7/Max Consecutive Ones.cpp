class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int zero =0;
        int maxi =0;
        for(int i=0;i<n;++i){
            if(nums[i] == 0){
                maxi = max(maxi,i-zero);
                zero=i+1;
            }
        }
        maxi = max(maxi,n - zero);
        return maxi;
    }
};
