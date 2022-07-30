class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<int>adj[n];
        vector<int>ans;
        int dp[n]; memset(dp,0,sizeof(dp));
        for(vector<int>v : pr) {
            adj[v[1]].push_back(v[0]);
            dp[v[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(dp[i]==0) q.push(i);
        }
        int c=n;
        while(!q.empty()) {
            int k=q.front();
            ans.push_back(k);
            q.pop();
            c--;
            for(int i : adj[k]) {
                dp[i]--;
                if(dp[i]==0) q.push(i);
            }
        }
        if(c) return {};
        return ans;
    }
};