class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        vector<vector<int>>adj[n+1];
        for(vector<int>v : t) {
            adj[v[0]].push_back({v[1],v[2]});
        }
       for(int i=1;i<=n;i++) dp[i]=INT_MAX;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        q.push({k,0});
        dp[k]=0;
        int ans=-1;
        while(!q.empty()) {
            vector<int>p = q.top(); q.pop();
            int x=p[0],y=p[1];
            
            for(vector<int>d : adj[x]) {
                int a=d[0],b=d[1];
                if(dp[a] > b+y) {
                    dp[a]=b+y;
                     q.push({a,b+y});
                }
            }
        }
        for(int i=1;i<=n;i++) {
            if(dp[i]==INT_MAX) return -1;
            ans=max(ans,dp[i]);
        }
        return ans;
            
    }
};