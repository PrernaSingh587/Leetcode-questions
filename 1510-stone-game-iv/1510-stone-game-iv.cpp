class Solution {
public:
    int isSqr(int n) {
        int h=sqrt(n);
       // cout<<h<<" ";
        return (h*h)==n;
    }
    
    int solve(int n) {
        if(n==0) return 0;
        // int ans=INT_MIN;
        // for(int i=1;i<=n;i++) {
        //     if(isSqr(i)) {
        //         ans=max(ans,i-solve(n-i));
        //     }
        // }
        // return ans==INT_MIN?0:ans;
        vector<bool> dp(n+1,0);
        for(int i=1;i<=n;i++)
            for(int j=1;j*j<=i;j++)
                if(!dp[i-j*j]) { dp[i]=true; break;}
        return dp[n];
    }
    bool winnerSquareGame(int n) {
        int h=solve(n);
        return h>0;
    }
};