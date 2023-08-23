class Solution {
private:
    void solve(vector<int>& candidates, int target,int sum,vector<int> output,vector<vector<int>> &ans,int ind){   
        if(sum == target){
            ans.push_back(output);
            return;
        }
        if(sum > target || ind >= candidates.size()){
            //ans.push_back(output);
            return;
        }
        //include
        output.push_back(candidates[ind]);
        solve(candidates, target, sum + candidates[ind], output, ans, ind);
        //dont include
        output.pop_back();
        solve(candidates,target,sum,output,ans,ind+1);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> output;
        int sum = 0;
        solve(candidates,target,sum,output,ans,0);
        return ans;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
private:
    void solve(vector<int>& candidates, int target,vector<int> output,vector<vector<int>> &ans,int ind){   
        if(ind >= candidates.size()){
            if(target == 0){
                ans.push_back(output);
            }
            return;
        }
        if(candidates[ind] <= target){
            output.push_back(candidates[ind]);
            solve(candidates,target-candidates[ind],output,ans,ind);
            output.pop_back();
        }
        solve(candidates,target,output,ans,ind+1);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> output;
        solve(candidates,target,output,ans,0);
        return ans;
    }
};
