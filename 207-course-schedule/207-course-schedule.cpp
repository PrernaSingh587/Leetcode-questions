class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<int>adj[n];
        int dp[n]; memset(dp,0,sizeof(dp));
        for(vector<int>v : pr) {
            adj[v[0]].push_back(v[1]);
            dp[v[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(dp[i]==0) q.push(i);
        }
        int c=n;
        while(!q.empty()) {
            int k=q.front();
            q.pop();
            c--;
            for(int i : adj[k]) {
                dp[i]--;
                if(dp[i]==0) q.push(i);
            }
        }
        return c==0;
    }
};