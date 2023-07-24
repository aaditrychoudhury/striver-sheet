// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//            vector<vector<int>> ans;
//            int n = nums.size();
//            if(nums.empty()) return ans;
//            sort(nums.begin(),nums.end());
//            for(int i=0;i<n-3;++i){
//               // if(i > 0 && nums[i] == nums[i-1]) continue;
//               long long sum = target - nums[i];
//                for(int j = i+1;j<n-2;++j){
//                    //if(j>i+1 && nums[j] == nums[j-1]) continue;
//                    int k = j+1;
//                    int l = n-1;
//                   long long sum1 = sum - nums[j];
//                    while(k<l){
//                        long long sum2 = nums[k] + nums[l];
//                        if(sum1 == sum2){
//                            vector<int> temp(4,0);
//                            temp[0] = nums[i];
//                            temp[1]= nums[j];
//                            temp[2] = nums[k];
//                            temp[3] = nums[l];
//                            ans.push_back(temp);
//                            //++k;--l;
//                            while(k<l && nums[k] == nums[2]) ++k;
//                            while(k<l && nums[l] == nums[3]) --l;
//                        }else if(sum2 < sum1) ++k;
//                        else --l;
//                    }
//                    while(j+1 < n && nums[j] == nums[j+1])++j;
//                }
//              while(i+1 < n && nums[i] == nums[i+1])++i;
//            }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (nums.empty()) return ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int k = j + 1;
                int l = n - 1;
                long long sum = target - nums[i];
                long long int remainingSum = sum - nums[j];
                
                while (k < l) {
                    int twoSum = nums[k] + nums[l];
                    
                    if (twoSum == remainingSum) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) ++k;
                        while (k < l && nums[l] == nums[l - 1]) --l;
                        ++k;
                        --l;
                    } else if (twoSum < remainingSum) {
                        ++k;
                    } else {
                        --l;
                    }
                }
            }
        }
        
        return ans;
    }
};
