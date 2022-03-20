class Solution {
public:
     int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
     int mx=1;
     vector<vector<int>>vis,dis;
     int dfs(vector<vector<int>>& mat,int n, int m,int x,int y) {
         if(vis[x][y]) return vis[x][y];
        // dis[x][y]=1;
         int ans=1;
         for(int i=0;i<4;i++) {
             int X=x+dx[i],Y=y+dy[i];
             if(X>=0 && Y>=0 && X<n && Y<m ) {
                 if(mat[X][Y]>mat[x][y]) {
                     if(vis[X][Y]) {
                         ans=max(ans,vis[X][Y]+1);
                     } else {
                        ans=max(ans,1+dfs(mat,n,m,X,Y));
                     }
                 }
             }
         }
       //  dis[x][y]=0;
       //  cout<<mat[x][y]<<" "<<ans<<endl;
         return vis[x][y]=ans;
         
     }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vis.resize(n,vector<int>(m,0));
         dis.resize(n,vector<int>(m,0));
       
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j]) {
                    int c=0;
                    dfs(mat,n,m,i,j);
                    mx=max(vis[i][j],mx);
                }
            }
        }
        
        return mx;
    }
};