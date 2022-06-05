class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        for(int i=n-2;i>=0;i--) {
            g[i][m-1]+=g[i+1][m-1];
        }
        for(int j=m-2;j>=0;j--) g[n-1][j]+=g[n-1][j+1];
        
        for(int i=n-2;i>=0;i--) {
            for(int j=m-2;j>=0;j--)
                g[i][j]+=min(g[i+1][j],g[i][j+1]);
        }
        return g[0][0];
    }
};