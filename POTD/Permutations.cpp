class Solution {
    void solve(vector<int>& nums,vector<vector<int>> &ans,int start){
        if(start >= nums.size()){
            ans.push_back(nums);
            return;
        }
        //temp.push_back(start);
        for(int i=start;i<nums.size();++i){
            swap(nums[start],nums[i]);
            solve(nums,ans,start+1);
            swap(nums[start],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};
