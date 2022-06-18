class Solution {
public:
    int dp[501][501];
    int solve(vector<int>p, int i,int j) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        maxi=max(p[j]-solve(p,i,j-1),p[i]-solve(p,i+1,j));
        return dp[i][j]=maxi;
    }
    bool stoneGame(vector<int>& p) {
        int n=p.size();
        memset(dp,-1,sizeof(dp));
        int h=solve(p,0,n-1);
        return h>0;
    }
};