class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
       // int dp[m][n]; memset(dp,0,sizeof(dp));
        for(int i=m-2;i>=0;i--) {
            g[i][n-1]+=g[i+1][n-1];
        }
        for(int i=n-2;i>=0;i--) {
             g[m-1][i]+=g[m-1][i+1];
        }
        
        for(int i=m-2;i>=0;i--) {
            for(int j=n-2;j>=0;j--) {
                g[i][j]=min(g[i+1][j],g[i][j+1])+g[i][j];
            }
        }
        return g[0][0];
    }
};