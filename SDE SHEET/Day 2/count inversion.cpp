//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    private:
     long long int merge(long long arr[], long long low,long long mid,long long high){
        long long int cnt=0;
        vector<long long> temp;
        long long left = low;
        long long right = mid+1;
        while(left <= mid && right <= high){
            if(arr[left] > arr[right]) {
                cnt+= (mid-left+1);
                temp.push_back(arr[right]);
                right++;
            }
            else{
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;++i){
            arr[i] = temp[i-low];
        }
        return cnt;
    }
    long long int mergeSort(long long arr[], long long low,long long high){
        long long int cnt=0;
        if(low>=high) return cnt;
        long long mid = (low + high)/2;
        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        return cnt;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
       
        return mergeSort(arr,0,N-1);
    
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
