//Approach 1
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        map<int,int> mp;
        for(int i =0;i<n;++i)mp[arr[i]]++;
        for(int i=1;i<=n;++i){
            if(mp[i] == 2) ans[0] = i;
            else if(mp[i] == 0) ans[1] =i;
        }
        return ans;
    }
};


//######################################################################################################################################################################
//Approach 2
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        long long int N = n;
        long long int x=0,y=0;
        long long int s1 = (N*(N+1))/2;
        long long int s2 = (N*(N+1)*(2*N+1))/6;
        for(long long int i=0;i<N;++i){
            s1-= (long long int) arr[i];
            s2-= ((long long int) arr[i]) * ((long long int) arr[i]);
        }
        long long int s3 = s2/s1;
        // x-y = s1;
        // x+y=s3;
        x = (s1+s3)/2;
        y = x-s1;
        int *ans = new int[2];
        ans[0]=(int)y;
        ans[1]=(int)x;
        return ans;
        
    }
};
//##########################################################################################################################################################################################
//Approach 3

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
         int xor1=0;int p=0;int q=0;
         for(int i=0;i<n;i++){
             xor1=xor1^arr[i]^(i+1);
         }
         
         //find the number with only rightmost set bit of xor1 
         int x=xor1 & (-xor1);
         
         //dividing to two buckets elements with set bit as x and 
         //those who are not

         //XORing with arr
         for(int i=0;i<n;i++){
             if(x&arr[i]){
                 p=p^arr[i];
             }else{
                 q=q^arr[i];
             }
         }

         //XORing with {1 to n}
         for(int i=1;i<=n;i++){
             if(x&i){
                 p=p^i;
             }else{
                 q=q^i;
             }
         }
         
         // either of p and q is repeating and missing 
         
         //check count
         int cnt=0;
         for(int i=0;i<n;i++){
             if(arr[i]==p){
                 cnt++;
             }
         }
         
         //storing answer
         int *ans=new int[2];
         if(cnt>1) {
             ans[0]=p;
             ans[1]=q;
         }else{
             ans[0]=q;
             ans[1]=p;
         }
         
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
