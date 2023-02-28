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

