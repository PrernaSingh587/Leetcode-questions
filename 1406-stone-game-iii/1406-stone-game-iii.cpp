class Solution {
public:
    int solve(vector<int>& s,int k) {
        // if(k>=s.size()) return 0;
        int ans=INT_MIN,sum=0,n=s.size();
        // for(int i=k;i<min((k+3),n);i++) {
        //     sum+=s[i];
        //     ans=max(ans,sum-solve(s,i+1));
        // }
        // return ans;
        int dp[n+3];
        for(int i=0;i<3;i++)
        s.push_back(0);
        
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--) {
            int sum=0; dp[i]=INT_MIN;
            for(int l=0;l<3;l++) {
                sum+=s[i+l];
                dp[i]=max(dp[i],sum-dp[i+l+1]);
            }
            //cout<<dp[i]<<" ";
        }
        return dp[0];
    }
    string stoneGameIII(vector<int>& s) {
        int h=solve(s,0);
        if(h==0) return "Tie";
        if(h>0) return "Alice";
        if(h<0) return "Bob";
        return "";
    }
};