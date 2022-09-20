class Solution {
public:
    int findLength(vector<int>& nm1, vector<int>& nm2) {
        int n1=nm1.size(),n2=nm2.size();
        
        int dp[n1+1][n2+1],maxi=0;
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        
        for(int i=1;i<=n1;i++) {
            for(int j=1;j<=n2;j++) {
                if(nm1[i-1]==nm2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                } else dp[i][j]=0;
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
    }
};