class Solution {
public:
    bool dfs(int k, int n, vector<int>adj[], int *vis,int par) {
        vis[k]=1;
        for(int i : adj[k]) {
            if(par==i) continue;
             if(vis[i]) return 0;
        else {
            if(dfs(i,n,adj,vis,k)==0) return 0; 
        }
        }
           
        return 1;
    }
    bool validTree(int n, vector<vector<int>>& ed) {
        vector<int>adj[n];
        for(vector<int>v : ed) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int vis[n]; memset(vis,0,sizeof(vis));
        if(dfs(0,n,adj,vis,-1)==0)  return 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
               return 0; 
            }
        }
        return 1;
    }
};