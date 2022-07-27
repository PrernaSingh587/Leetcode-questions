class Solution {
public:
    int bs(vector<int>& nums, int target,int x,int y,int k) {
        if(k==0) {
            int i=x,j=y;
            while(i<=j) {
                int m=(i+j)/2;
                if(nums[m]==target) {
                    return m;
                } else if(nums[m]<target) {
                    i=m+1;
                } else {
                    j=m-1;
                }
            }
        } else if(k==1) {
            int i=x,j=y,ans;
            while(i<=j) {
                int m=(i+j)/2;
                if(nums[m]==target) {
                    ans=m;
                    j=m-1;
                } else if(nums[m]<target) {
                    i=m+1;
                } else {
                    j=m-1;
                }
            }
            return ans;
        } else {
            int i=x,j=y,ans;
            while(i<=j) {
                int m=(i+j)/2;
                if(nums[m]==target) {
                    ans=m;
                    i=m+1;
                } else if(nums[m]<target) {
                    i=m+1;
                } else {
                    j=m-1;
                }
            }
            return ans;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int t1,t2=-1,t3=-1;
        t1=bs(nums,target,0,nums.size()-1,0);
        if(t1==-1) return {-1,-1};
        t2=bs(nums,target,0,t1,1);
        t3=bs(nums,target,t1,nums.size()-1,2);
        return {t2,t3};
    }
};