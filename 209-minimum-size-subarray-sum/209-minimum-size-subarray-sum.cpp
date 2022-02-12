class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int ans=INT_MAX;
        int dp[nums.size()]; 
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++) dp[i]=dp[i-1]+nums[i];
        for(int i=0;i<nums.size();i++) { 
             int l=i,r=nums.size()-1;
             while(l<=r) {
                 int m=l+(r-l)/2;
                 if(i==0) {
                     if(dp[m]>=t) {
                         ans=min(ans,m+1);
                         r=m-1;
                     } else {
                         l=m+1;
                     }
                 } else {
                     if((dp[m]-dp[i-1])>=t) {
                          ans=min(ans,m-i+1);
                         r=m-1;
                     } else l=m+1;
                 }
             }
            // for(int j=i;j<nums.size();j++) {
            //     s+=nums[j];
            //     if(s>=t) {
            //         mini=min(mini,j-i+1); break;
            //     }
            // }
        }
        return ans==INT_MAX?0:ans;
    }
};