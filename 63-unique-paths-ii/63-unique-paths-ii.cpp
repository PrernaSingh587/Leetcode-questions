class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
    if(h == 0) return 0;
    int w = obstacleGrid[0].size();
    if(w == 0) return 0;
    if(obstacleGrid[0][0]) return 0;
    
    // first cell has 1 path
    obstacleGrid[0][0] = 1;
    
    // first row all are '1' until obstacle (from left only)
    for(int i=1; i<w; i++){
        obstacleGrid[0][i] = obstacleGrid[0][i] ? 0 : obstacleGrid[0][i-1];
    }

    for(int j=1; j<h; j++){
        // first column is like first row (from top only)
        obstacleGrid[j][0] = obstacleGrid[j][0] ? 0 : obstacleGrid[j-1][0];
        
        // others are up+left
        for(int i=1; i<w; i++){
            obstacleGrid[j][i] = obstacleGrid[j][i] ? 0 : obstacleGrid[j-1][i] + obstacleGrid[j][i-1];
        }
    }
    
    return obstacleGrid[h-1][w-1];
    }
};