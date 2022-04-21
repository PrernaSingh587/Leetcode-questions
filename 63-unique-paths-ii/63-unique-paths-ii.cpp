class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        
         int m=g.size(),n=g[0].size();
        if(m==0 || n==0) return 0;
        if(g[m-1][n-1] || g[0][0]) return 0;
        g[0][0]=1;
        for(int i=1;i<m;i++) {
            if(g[i-1][0]==0 ||g[i][0]==1 ) g[i][0]=0;
            else g[i][0]=1;
        }
        for(int i=1;i<n;i++) {
            if(g[0][i-1]==0 || g[0][i]==1) g[0][i]=0;
            else g[0][i]=1;
        }
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                if(g[i][j]==1) {
                    g[i][j]=0;
                } else {
                    g[i][j]=(g[i-1][j]+g[i][j-1]);
                }
            }
        }
       
        return g[m-1][n-1];
    }
};