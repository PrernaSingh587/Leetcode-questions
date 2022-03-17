class Solution {
public:
    pair<int,int> dfs(pair<int,int>pis[],int *vis,int k,vector<int>adj[],int n
                     , vector<int>& q) {
        vis[k]=1;
        int x=q[k],y=k;
        for(int i : adj[k]) {
            if(!vis[i]) {
                auto h = dfs(pis,vis,i,adj,n,q);
                if(x>h.first) {
                    x=h.first;
                    y=h.second;
                }
            } else {
                if(x>pis[i].first) {
                    x=pis[i].first;
                    y=pis[i].second;
                }
            }
        }
       // cout<<" "<<y<<endl;
        return pis[k]={x,y};
    }
    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
        vector<int>adj[q.size()];
        for(vector<int>v : r) {
            adj[v[1]].push_back(v[0]);
        }
        int vis[q.size()],n=q.size();
        pair<int,int>pis[n];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(pis,vis,i,adj,n,q);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++) {
            ans.push_back(pis[i].second);
        }
        return ans;
    }
};