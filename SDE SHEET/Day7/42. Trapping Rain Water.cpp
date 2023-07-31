//approach tc= 3n and sc = 2n
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n],suffix[n];
        int maxi = INT_MIN;
        for(int i=0;i<n;++i){
            maxi = max(maxi,height[i]);
            prefix[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i=n-1;i>=0;--i){
            maxi = max(maxi,height[i]);
            suffix[i] = maxi;
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            ans += (min(prefix[i],suffix[i]) - height[i]);
        }
        return ans;
    }
};
//approach 2 two pointer 
class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int l =0,r=n-1,leftmax=0,rightmax =0;
        int water = 0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] >= leftmax) leftmax = height[l];
                else water += (leftmax-height[l]);
                ++l;
            }
            //height[r] >= height[l]
            else{
                if(height[r] >= rightmax) rightmax = height[r];
                else water += (rightmax-height[r]);
                --r;
            }
        }
        return water;
    }
};
