//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a ,Job b){
        return (a.profit > b.profit);
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //if(n==0) return {};
        sort(arr,arr+n,cmp);
        
        int maxDead = arr[0].dead;
        for(int i=1;i<n;++i){
            maxDead = max(maxDead,arr[i].dead);
        }
        vector<int> a(maxDead,-1);
        int cntjobs=0,jobprofit = 0;
        
        for(int i=0;i<n;++i){
            for(int j=arr[i].dead-1;j>=0;--j){
                if(a[j] == -1){
                    a[j] = i;
                    ++cntjobs;
                    jobprofit+=arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(cntjobs);
        ans.push_back(jobprofit);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
