class Solution {
public:
    int mincostTickets(vector<int>& d, vector<int>& c) {
        unordered_set<int>st(d.begin(),d.end());
        int n=d.size();
        int dp[d[n-1]+1];
        dp[0]=0;
        for(int i=1;i<=(d.back());i++) {
            if(st.find(i)==st.end()){ dp[i]=dp[i-1]; continue; }
            int a=INT_MAX,b=INT_MAX;
            // if((i-7)>=0) a=;
            // if((i-30)>=0) b=;
            dp[i]=min(c[0]+dp[i-1],min(dp[max(0,i-7)]+c[1],dp[max(0,i-30)]+c[2]));
           // cout<<dp[i]<<" ";
        }
        return dp[d.back()];
    }
};