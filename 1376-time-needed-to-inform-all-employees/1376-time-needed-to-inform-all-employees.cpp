class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& man, vector<int>& inf) {
        int maxi=0;
        vector<int>adj[n];
        for(int i=0;i<n;i++) {
            if(man[i]==-1) continue;
            adj[man[i]].push_back(i);
        }
        if(n==1) return 0;
        queue<vector<int>>q;
        q.push({h,0});
        int vis[n];
        memset(vis,0,sizeof(vis)); 
        vis[h]=1;
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                vector<int> kl=q.front(); q.pop();
                int k=kl[0],kk=kl[1];
                for(int i : adj[k]) {
                    if(vis[i]) continue;
                    //cout<<inf[k]<<" "<<kk<<" ";
                    q.push({i,inf[k]+kk});
                    vis[i]=1;
                    maxi=max(maxi,kk+inf[k]);
                }
            }
        }
        return maxi;
    }
};