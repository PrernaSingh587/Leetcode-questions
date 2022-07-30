class Solution {
public:
    bool validPath(int n, vector<vector<int>>& ed, int src, int dest) {
        vector<int>adj[n];
        for(vector<int>v : ed) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int dp[n]; memset(dp,0,sizeof(dp));
        dp[src]=1;
        queue<int>q;
        q.push(src);
        while(!q.empty()) {
            int k=q.front(); q.pop();
            if(k==dest) return 1;
            
            for(int i : adj[k]) {
                if(dp[i]==0) {
                    dp[i]=1;
                    q.push(i);
                }
            }
        }
        return 0;
    }
};