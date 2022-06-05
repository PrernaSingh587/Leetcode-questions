class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size(),r=mat[0].size();
        int m=0;
        for(int i=0;i<n;i++) {
        if(mat[i][0]) m++;
        }
        for(int i=1;i<r;i++) if(mat[0][i]) m++;
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<r;j++) {
                if(mat[i][j]==0) continue;
                int mini=min(mat[i-1][j],mat[i-1][j-1]);
                mini=min(mini,mat[i][j-1]);
                
                mat[i][j]=1+mini; 
                m+=mat[i][j];
            }
        }
        return m;
    }
};