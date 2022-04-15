class Solution {
public:
   int dp[1001][1101];
    int solve(vector<int>& st,int i,int j,int f,int sum) {
        if(i>j) return 0;
        int ans;
      if(dp[i][j]!=-1) return dp[i][j];
            return dp[i][j]=max(sum-st[i]-solve(st,i+1,j,!f,sum-st[i]),sum-st[j]-solve(st,i,j-1,!f,sum-st[j]));
        
    }
    int stoneGameVII(vector<int>& st) {
        int n=st.size(),sum=0;
        for(int i:st) sum+=i;
        memset(dp,-1,sizeof(dp));
        int h=solve(st,0,n-1,1,sum);
        return h;
    }
};