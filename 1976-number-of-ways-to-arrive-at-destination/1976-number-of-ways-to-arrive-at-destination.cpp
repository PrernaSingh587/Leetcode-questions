#define pp pair<long long, int>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& r) {
        if(n==1) return 1;
       vector<pair<int,int>>adj[n];
        for(vector<int>v : r) {
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        long long int con[n],par[n];
        memset(par,0,sizeof(par));
        con[0]=0;
        for(int i=1;i<n;i++) con[i]=LONG_MAX;
        priority_queue<pp,vector<pp>,greater<pp>>q;
        q.push({0,0});
        int ans=0;
        while(!q.empty()) {
            auto k=q.top(); q.pop();
            long long int x=k.first,y=k.second;
           // cout<<x<<" "<<y<<endl;
            if(con[y]<x) continue;
            
            for(pp d : adj[y]) {
                if((d.second+x)<con[d.first]) {
                    con[d.first]=(d.second+x);
                    par[d.first]=par[y]==0?1:par[y];
                    q.push({con[d.first],d.first});
                }  else if(d.second+x==con[d.first]) {
                    par[d.first]=(par[d.first]+par[y])%1000000007; 
                }
            }
        }
        return par[n-1];
    }
};