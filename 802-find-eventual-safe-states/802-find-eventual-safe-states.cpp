class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        int indeg[n]; memset(indeg,0,sizeof(indeg));
        vector<int>adj[n];
        for(int i=0;i<g.size();i++) {
            for(int k : g[i]) {
                adj[k].push_back(i);
                indeg[i]++;
            }
        }
        vector<int>v;
        queue<int>q;
        for(int i=0;i<n;i++) {
            if(indeg[i]==0) {q.push(i); v.push_back(i);}
        }
       
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                int k=q.front(); q.pop();
                for(int i : adj[k]) {
                    indeg[i]--;
                    if(indeg[i]==0) {
                        q.push(i);
                        v.push_back(i);
                    }
                }
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};