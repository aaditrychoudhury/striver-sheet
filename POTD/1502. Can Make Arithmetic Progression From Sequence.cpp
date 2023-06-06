class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;++i){
            int sub = abs(arr[i] - arr[i+1]); 
            mp[sub] ++;
        }
        if(mp.size() == 1)return true;
        return false;
    }
};
