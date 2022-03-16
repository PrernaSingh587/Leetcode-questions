class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pr, vector<vector<int>>& que) {
         vector<int>adj[num];
        //memset(indeg,0,sizeof(indeg));
        for(vector<int>v : pr) {
            adj[v[0]].push_back(v[1]);
        }
        int vis[num][num],mis[num][num]; memset(vis,0,sizeof(vis)); memset(mis,0,sizeof(mis));
        vector<bool>vas;
        for(int i=0;i<num;i++) {
            queue<int>q;
            q.push(i);
            while(!q.empty()) {
                int s=q.size();
                while(s--) {
                    int k=q.front(); q.pop();
                    for(int f : adj[k]){ 
                        if(mis[i][f]) continue;
                        mis[i][f]=1;
                        vis[i][f]=1; 
                        q.push(f);
                    }
                }
            }
        }
        for(vector<int>v : que) {
            vas.push_back((bool)vis[v[0]][v[1]]) ;
        }
        return vas;
    }
};