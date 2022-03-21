class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),maxi=0;
        if(n==0) return maxi;
        int dp[n]; memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++) {
            if(s[i]=='(') continue;
            if(s[i-1]=='(') {
                dp[i]=(i>=2?dp[i-2]:0)+2;
            } else {
                if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(') {
                    dp[i]=(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0)+dp[i-1]+2;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        
        return maxi;
    }
};