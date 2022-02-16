class Solution {
public:
    int vis[501][501];
    int solve(vector<int>p, int i,int j) {
        if(i==j) return p[i];
        if(vis[i][j]!=-1) return vis[i][j];
         return vis[i][j]=max(p[i]-solve(p,i+1,j),p[j]-solve(p,i,j-1));
    }
    bool stoneGame(vector<int>& p) {
        memset(vis,-1,sizeof(vis));
        int h=solve(p,0,p.size()-1);
        return h>0;
    }
};