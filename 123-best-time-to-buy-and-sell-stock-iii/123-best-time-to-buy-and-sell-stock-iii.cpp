class Solution {
public:
    // map<vector<int>,int>mp;
    // int p(vector<int>& pr,int k,int f,int tr) {
    //     if(k==pr.size() || tr==0) return 0;
    //     if(mp.count({k,f,tr})) return mp[{k,f,tr}];
    //     if(f==0) {
    //         return mp[{k,f,tr}]= max(p(pr,k+1,1,tr)-pr[k],p(pr,k+1,0,tr));
    //     } else {
    //         return mp[{k,f,tr}]=max(pr[k]+p(pr,k+1,0,tr-1),p(pr,k+1,f,tr));
    //     }
    // }
    int p(vector<int>& pr,int k,int f,int tr) {
        int n=pr.size();
        int dp[n+1][k+1][2];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<k;j++) {
                dp[i][j][0]=max(-pr[i]+dp[i+1][j][1],dp[i+1][j][0]);
                dp[i][j][1]=max(pr[i]+dp[i+1][j+1][0],dp[i+1][j][1]);
            }
        }
        return dp[0][0][0];
    }
    int maxProfit(vector<int>& pr) {
        return p(pr,2,0,2);
    }
};