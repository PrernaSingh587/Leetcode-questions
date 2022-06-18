class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size(),m=INT_MAX;
        if(n==1) return mat[0][0];
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<n;j++) {
                if(j==0) {
                    mat[i][j]+=min(mat[i+1][j],mat[i+1][j+1]);
                } else if(j==n-1) {
                     mat[i][j]+=min(mat[i+1][j-1],mat[i+1][j]);
                } else {
                    mat[i][j]+=min(mat[i+1][j-1],min(mat[i+1][j],mat[i+1][j+1]));
                }
                if(i==0) m=min(m,mat[i][j]);
            }
        }
        return m;
        
    }
};