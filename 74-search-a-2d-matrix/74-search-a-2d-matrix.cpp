class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m=mat.size(),n=mat[0].size();
        int i=m-1,j=0;
        while(i>=0 && j>=0 && i<m && j<n ) {
            //cout<<mat[i][j]<<" ";
            if(mat[i][j]>tar) {
                i--;
            } else if(mat[i][j]<tar) j++;
            else return 1;
        }
        return 0;
    }
};