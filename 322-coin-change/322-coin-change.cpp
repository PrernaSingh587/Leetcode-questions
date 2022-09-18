class Solution {
public:
    int coinChange(vector<int>& c, int amt) {
        int n=c.size();
        int dp[n+1][amt+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=amt;i++) dp[0][i]=INT_MAX-1;
        
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amt;j++) {
                if(c[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(1+dp[i][j-c[i-1]],dp[i-1][j]);
            }
        }
        return dp[n][amt]!=((INT_MAX-1))?dp[n][amt]:-1;
    }
};