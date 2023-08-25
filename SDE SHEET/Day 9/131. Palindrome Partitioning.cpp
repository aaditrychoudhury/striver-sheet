class Solution {
    
private:
    bool isPalindrome(int start,int end,string s){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void solve(int ind,vector<string> temp,vector<vector<string>> &ans,string s){
        if(ind >= s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i = ind;i<s.length();++i){
            if(isPalindrome(ind,i,s)){
                temp.push_back(s.substr(ind,i-ind+1));
                solve(i+1,temp,ans,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,temp,ans,s);
        return ans;
    }
};
