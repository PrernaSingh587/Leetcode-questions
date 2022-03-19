class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        //int vis[n][m]; memset(vis,0,sizeof(vis));
        int ans=0;
        int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
         queue<vector<int>>q;
        int fresh=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                 if(g[i][j]==2)
                    q.push({i,j}); 
                else if(g[i][j]==1) fresh++;
            }
        }
                int fff=0;
                    while(!q.empty()) {
                        fff=1;
                        int s=q.size();
                        ans++;
                        while(s--) {
                            vector<int>v=q.front(); q.pop();
                            for(int k=0;k<4;k++) {
                                int X=v[0]+dx[k],Y=dy[k]+v[1];
                                if(X>=0 && Y>=0 && X<n && Y<m
                                  && g[X][Y]==1) {
                                    g[X][Y]=0; fresh--;
                                    q.push({X,Y});
                                }
                            }
                        }
                    }
                
            
        if(fff==0 && fresh==0) return 0;
        return fresh==0?ans-1:-1;
    }
};