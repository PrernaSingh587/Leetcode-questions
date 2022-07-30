class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        int cost[n];
        for(int i=0;i<n;i++) cost[i]=INT_MAX;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
        vector<vector<int>>adj[n];
        for(vector<int>v: fl) {
            adj[v[0]].push_back({v[1],v[2]});
        }
        q.push({0,0,src});
        cost[src]=0;
        while(!q.empty()) {
            vector<int>v=q.top();
            q.pop();
            int x=v[0],y=v[1],z=v[2];
            
            if(z==dst) return x;
            if(y >= k+1) continue;
            if(cost[z] < y) continue;
            cost[z]=y;
            for(vector<int>p : adj[z]) {
               
                     q.push({p[1]+x,y+1,p[0]});
                  
            }
        }
        return -1;
    }
};