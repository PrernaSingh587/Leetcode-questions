class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& ed) {
        vector<int>adj[n];
        int indeg[n]; memset(indeg,0,sizeof(indeg));
        for(vector<int>v : ed) {
            adj[v[0]].push_back(v[1]);
            indeg[v[1]]++;
        }
        queue<int>q;
        vector<vector<int>>ans(n);
        set<int>st[n];
        for(int i=0;i<n;i++) {
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int k=q.front(); q.pop();
            for(int i : adj[k]) {
                indeg[i]--; 
                if(indeg[i]==0) {
                     //cout<<i<<" "<<k<<" "<<ans;
                    q.push(i);
                } 
                    for(auto d=st[k].begin();d!=st[k].end();d++) {
                        st[i].insert(*d);  
                    }
                   st[i].insert(k);
                   
               
            }
        }
        for(int i=0;i<n;i++) {
            for(auto d=st[i].begin();d!=st[i].end();d++) {
                        ans[i].push_back(*d);  
                    }
        }
        return ans;
    }
};