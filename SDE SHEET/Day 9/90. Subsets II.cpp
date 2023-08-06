class Solution {
private:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> temp,int ind, bool prev){
        if(ind == nums.size()){
            ans.push_back(temp);
            return;
        }
        //dont take
        solve(nums,ans,temp,ind+1,false);
        if(ind > 0 && nums[ind] == nums[ind-1] && !(prev)) return;
        temp.push_back(nums[ind]);
        solve(nums,ans,temp,ind+1,true);
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,temp,0,false);
        return ans;
    }
};
