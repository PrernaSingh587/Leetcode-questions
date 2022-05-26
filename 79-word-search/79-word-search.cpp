class Solution {
public:
    int vis[16][16];
 int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool dfs(int n,int m,int x,int y, string a,string ans,vector<vector<char>> &A,int top) {
   // cout<<ans<<" ";
    if(ans==a) return 1;
    if(ans.size()==a.size()) return 0;
    vis[x][y]=1;
    for(int i=0;i<4;i++) {
        int X=x+dx[i],Y=y+dy[i];
        if(X>=0 && Y>=0 && X<n && Y<m && vis[X][Y]==0 && A[X][Y]==a[top]) {
            if(dfs(n,m,X,Y,a,ans+A[X][Y],A,top+1)) return 1;
        }
    }
    vis[x][y]=0;
    return 0;
}
    bool exist(vector<vector<char>>& A, string B) {
        int n=A.size(),m=A[0].size();
    
    memset(vis,0,sizeof(vis));
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<A[0].size();j++) {
            if(A[i][j]==B[0]) {
                string h="";
                h+=B[0];
                if(dfs(n,m,i,j,B,h,A,1)) return 1;
            }
            
        }
    }
    return 0;
    }
};