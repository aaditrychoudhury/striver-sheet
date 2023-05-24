//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        vector<int> steps(100000,1e9);
        steps[start] = 0;
        //{steps,node}
        queue<pair<int,int>> q;
        q.push({0,start});
        while(!q.empty()){
            auto it = q.front();
            int step = it.first;
            int node = it.second;
            q.pop();
            for(int i=0;i<n;++i){
                int mul = (node*arr[i]) % 100000;
                if(mul == end) return step+1;
                if(step+1 < steps[mul]) {
                    steps[mul] = step+1;
                    q.push({steps[mul],mul});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
