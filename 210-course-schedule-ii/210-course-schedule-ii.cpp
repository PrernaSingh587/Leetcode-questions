class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pr) {
        vector<int>adj[num];
        int indeg[num]; memset(indeg,0,sizeof(indeg));
        for(vector<int>v : pr) {
            adj[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }
        queue<int>q;
        int c=num;
        for(int i=0;i<num;i++) {
            if(indeg[i]==0) q.push(i);
        }
         vector<int>v;
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                int k=q.front(); q.pop(); num--;
                v.push_back(k);
                for(int h : adj[k]) {
                    indeg[h]--;
                    if(indeg[h]==0) q.push(h);
                }
            }
        }
        if(num!=0) return {};
        return v;
        
    }
};