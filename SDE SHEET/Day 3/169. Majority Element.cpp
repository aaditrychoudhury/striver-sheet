class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt =0,candidate =0;
        for(auto num:nums){
            if(cnt == 0) candidate = num;
             if(candidate == num) ++cnt;
            else --cnt;
        }
        return candidate;
    }
};
