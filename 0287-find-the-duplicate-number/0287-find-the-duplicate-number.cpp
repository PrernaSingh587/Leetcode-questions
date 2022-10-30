class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=1,j=n-1,ans=-1;
        while(i<=j) {
            int m=(i+j)/2;
            int c=0;
            for(int k:nums) if(k<=m) c++;
            if(c<=m) {
                i=m+1;
            } else if(c>m) {
                ans=m;
                j=m-1;
            }
        }
        
        return ans;
    }
};