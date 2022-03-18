class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        //int vis[n][m]; memset(vis,0,sizeof(vis));
        int ans=0;
        int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(g[i][j]==1) {
                    queue<vector<int>>q;
                    q.push({i,j});
                    g[i][j]=0; int c=0;
                    while(!q.empty()) {
                        int s=q.size();
                        while(s--) {
                            vector<int>v=q.front(); q.pop(); c++;
                            for(int k=0;k<4;k++) {
                                int X=v[0]+dx[k],Y=dy[k]+v[1];
                                if(X>=0 && Y>=0 && X<n && Y<m
                                  && g[X][Y]==1) {
                                    g[X][Y]=0;
                                    q.push({X,Y});
                                }
                            }
                        }
                    }
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};