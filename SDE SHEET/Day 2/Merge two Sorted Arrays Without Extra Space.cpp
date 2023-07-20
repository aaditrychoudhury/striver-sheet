class Solution {
    private:
    void swapIfGreater(vector<int>& nums1,vector<int>& nums2,int i,int j){
        if(nums1[i] > nums2[j]) swap(nums1[i],nums2[j]);
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int len = m+n;
        int gap = (len/2) + (len%2);
        while(gap>0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                //in arr1 and arr2
                if(left<m && right>=m)
                    swapIfGreater(nums1,nums2,left,right-m);
                else if(left>=m)
                    swapIfGreater(nums2,nums2,left-m,right-m);
                else{
                    swapIfGreater(nums1,nums1,left,right);
                }
                ++left;
                right++;
            }
            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
        }
        for(int i=m;i<len;++i){
            nums1[i] = nums2[i-m];
        }
    }
};
