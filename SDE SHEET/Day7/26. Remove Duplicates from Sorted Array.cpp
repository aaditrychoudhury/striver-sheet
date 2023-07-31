//approach 1 using set TC = o(nlogn) SC=(n);
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i=0;i<n;++i) st.insert(nums[i]);
        int k = st.size();
        int i=0;
        for(auto it: st){
            nums[i] = it;
            ++i;
        }
        return k;
    }
};
//etwo pointer approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=1;
        while(j<n){
          if(nums[i] != nums[j]){
                ++i;
                swap(nums[i],nums[j]);
            }
            ++j;
        }
        return i+1;
    }
};
