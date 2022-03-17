class Solution {
public:
     vector<vector<int>> ans;
    void dfs(int k, int n, vector<int>adj[],vector<int>c) {
        c.push_back(k);
        if(k==n-1) {
            ans.push_back(c);
            return;
        }
        for(int d : adj[k]) {
            dfs(d,n,adj,c);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>adj[n];
        int top=0;
        for(vector<int>v : g) {
            for(int i : v) {
                adj[top].push_back(i);
            }
            top++;
        }
        dfs(0,n,adj,{});
        return ans;
    }
};