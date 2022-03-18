class Solution {
public:
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        
        int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
        int n=g1.size(),m=g1[0].size();
        int vis[n][m]; memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && g2[i][j]==1 && g1[i][j]) {
                    queue<vector<int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                    int ff=0;
                    while(!q.empty()) {
                        int s=q.size();
                        while(s--) {
                            vector<int>f=q.front(); q.pop();
                            for(int d=0;d<4;d++) {
                                int X=f[0]+dx[d],Y=f[1]+dy[d];
                                if(!(X>=0 && Y>=0 && X<n && Y<m) || 
                                  vis[X][Y]) continue;
                                   if(g2[X][Y]==1 
                                   && g1[X][Y]==1) {
                                    vis[X][Y]=1;
                                    q.push({X,Y});
                                } else if(g2[X][Y]==1 
                                   && g1[X][Y]!=1) {
                                       ff=1; vis[X][Y]=1;
                                    q.push({X,Y});
                                   }
                            }
                           
                        }
                       
                    }
                    if(!ff)
                    ans++;
                }
            }
        }
        return ans;
    }
};