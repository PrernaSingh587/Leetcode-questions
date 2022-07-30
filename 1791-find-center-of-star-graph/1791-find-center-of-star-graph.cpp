class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        int n=ed.size()+1;
        int dp[n+1]; memset(dp,0,sizeof(dp));
        for(vector<int>v : ed) {
            dp[v[0]]++;
            dp[v[1]]++;
        }
        for(int i=1;i<=n;i++) {
            if(dp[i]==n-1) return i;
        }
        return -1;
    }
};