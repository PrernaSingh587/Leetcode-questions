class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return 0;
        if(s.size()==t.size()) return s==t;
        int dp[s.size()+1][t.size()+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=s.size();i++) {
            for(int j=1;j<=t.size();j++) {
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                } else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[s.size()][t.size()]==s.size();
    }
};