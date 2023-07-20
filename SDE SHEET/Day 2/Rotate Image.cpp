class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rows;
        for(int i=0;i<n;++i){
            vector<int> temp;
            for(int j=0;j<n;++j)
                temp.push_back(matrix[i][j]);
            rows.push_back(temp);
        }
        for(int j=0;j<n;++j){
            for(int i=0;i<n;++i){
                matrix[i][j] = rows[n-j-1][i];
            }
        }
    }
};
