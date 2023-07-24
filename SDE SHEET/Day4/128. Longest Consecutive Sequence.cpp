//Better solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;
        int lastSmaller = nums[0];
        int cnt=1;    
        for(int i=1;i<n;++i){
            if(nums[i] == lastSmaller+1){
                cnt++;
                lastSmaller = nums[i];
                longest = max(longest,cnt);
            }
            else if(nums[i] == lastSmaller){
                continue;
            }
            else{
                cnt =1;
                lastSmaller= nums[i];
            }
        }
        return longest;
    }
};
//Optimal Solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int i=0;i<n;++i)st.insert(nums[i]);
        for(auto it:st){
            if(st.find(it-1) == st.end()){
                int cnt =1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x=x+1;
                    cnt=cnt+1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
