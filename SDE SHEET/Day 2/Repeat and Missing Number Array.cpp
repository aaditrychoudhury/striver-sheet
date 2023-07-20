vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int> ans;
    int arr[n+1] = {0};
    for(int i=0;i<n;++i){
        arr[A[i]]++;
    }
    int rep=-1,miss=-1;
    for(int i=1;i<n+1;++i){
        if(arr[i] == 0) miss = i;
        else if (arr[i] == 2) rep = i;
    }
    ans.push_back(rep);
    ans.push_back(miss);
    return ans;
