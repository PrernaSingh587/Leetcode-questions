class Solution {
public:
    int maxProfit(int k, vector<int>& pr) {
        int n=pr.size();
        int dp[2][k+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<k;j++) {
                dp[0][j][i]=max(dp[0][j][i+1],-pr[i]+dp[1][j][i+1]);
                dp[1][j][i]=max(dp[1][j][i+1],pr[i]+dp[0][j+1][i+1]);
            }
        }
        return dp[0][0][0];
    }
};