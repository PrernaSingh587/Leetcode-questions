class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        int dp[n+1],mp[n+1]; memset(dp,0,sizeof(dp));
        memset(mp,0,sizeof(mp));
        for(vector<int>c : t) {
            mp[c[0]]++;
            dp[c[1]]++;
        }
        int x=0;
        for(int i=1;i<=n;i++) {
            if(dp[i]==n-1) {
                if(x==0) x=i;
                else return -1;
            }
        }
        if(x==0) return -1;
        return mp[x]==0?x:-1;
    }
};