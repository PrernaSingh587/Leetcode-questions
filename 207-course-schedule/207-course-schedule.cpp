class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int c=num,indeg[c]; memset(indeg,0,sizeof(indeg));
        vector<int>adj[num];
        for(vector<int>v : pre) { adj[v[1]].push_back(v[0]); indeg[v[0]]++; }
        queue<int>q;
        for(int i=0;i<num;i++) if(indeg[i]==0) q.push(i);
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                int k=q.front(); q.pop();
                c--;
                for(int h : adj[k]) {
                    indeg[h]--;
                    if(indeg[h]==0) q.push(h);
                }
            }
        }
        return c==0;
    }
};