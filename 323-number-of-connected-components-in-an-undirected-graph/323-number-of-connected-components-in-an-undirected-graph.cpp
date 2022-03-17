class Solution {
public:
    void dfs(int k, int n,  vector<int>adj[],int *vis) {
        vis[k]=1;
        for(int i : adj[k]) {
            if(!vis[i]) dfs(i,n,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& ed) {
        vector<int>adj[n];
        for(vector<int>v : ed) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int vis[n],ans=0;; memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i,n,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};