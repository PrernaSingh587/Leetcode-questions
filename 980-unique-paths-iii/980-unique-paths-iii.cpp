class Solution {
public:
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    int vis[21][21];
    int dfs(vector<vector<int>>& g,int c,int x,int y,int e1,int e2 ) {
        if(x==e1 && y==e2) return c==0?1:0;
        int ans=0;
        vis[x][y]=1;
        for(int i=0;i<4;i++) {
            int X=x+dx[i],Y=y+dy[i];
            if(X>=0 && Y>=0 && X<g.size() && Y<g[0].size()
              && vis[X][Y]==0 && g[X][Y]!=-1) {
                ans+=dfs(g,c-1,X,Y,e1,e2);
            }
        }
        vis[x][y]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        int c=n*m,x,y,e1,e2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(g[i][j]==-1) c--;
                if(g[i][j]==1) {
                    x=i; y=j;
                }
                 if(g[i][j]==2) {
                    e1=i; e2=j;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        return dfs(g,c-1,x,y,e1,e2);
    }
};