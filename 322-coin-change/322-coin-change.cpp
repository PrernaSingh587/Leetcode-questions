class Solution {
public:
    int coinChange(vector<int>& c, int amt) {
        int n=c.size();
        int dp[amt+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=amt;i++) dp[i]=INT_MAX;
        
        for(int i=1;i<=amt;i++) {
            for(int j=0;j<n;j++) {
                if(i-c[j]>=0 && dp[i-c[j]]!=INT_MAX) {
                    dp[i]=min(dp[i],1+dp[i-c[j]]);
                }
            }
        }
        return dp[amt]==INT_MAX?-1:dp[amt];
    }
};