#define pp vector<int> 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        vector<vector<int>>adj[n];
        for(vector<int>v : fl) {
            adj[v[0]].push_back({v[1],v[2]});
        }
        int dis[n],stops[n]; 
        for(int i=0;i<n;i++) {dis[i]=INT_MAX; stops[i]=0;}
        dis[src]=0; stops[src]=-1;
        priority_queue<pp,vector<pp>,greater<pp>>q;
        q.push({0,-1,src});
        while(!q.empty()) {
            vector<int>v = q.top(); q.pop();
            int dist=v[0],st=v[1],pos=v[2];
           
            if(dis[pos]<dist && stops[pos]<st) {
                 continue;
            }  dis[pos]=min(dis[pos],dist);
            stops[pos]=st;
            for(vector<int> f : adj[pos]) {
                
                    if((st+1)<=k)
                    q.push({v[0]+f[1],st+1,f[0]});
                
            }
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};