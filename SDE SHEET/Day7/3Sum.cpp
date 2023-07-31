class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int lo = i+1,high = nums.size()-1,sum = 0-nums[i];
            while(lo<high){
                    if(nums[lo]+nums[high] == sum){
                        vector<int> temp(3,0);
                        temp[0] = nums[i];
                        temp[1] = nums[lo];
                        temp[2] = nums[high];
                        ans.push_back(temp);
                    while(lo < high && nums[lo] == temp[1]) ++lo;
                    while(lo < high && nums[high] == temp[2]) --high;
                    }else if((nums[lo] + nums[high]) < sum)++lo;
                    else --high;
            }
            
        }
        return ans;
    }
};
