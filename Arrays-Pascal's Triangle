class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i =0;i<numRows;++i){
            vector<int> ot;
            
            for(int j =0;j<=i;++j){
                if(j == 0 || j == i){
                    ot.push_back(1);
                }
                else{
                    ot.push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
           
            ans.push_back(ot);
        }
        return ans;
    }
};
