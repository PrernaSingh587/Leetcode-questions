class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        queue<vector<int>>q;
        int n=land.size(),m=land[0].size();
        int vis[n][m];
        int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && land[i][j]) {
                    vis[i][j]=1;
                    vector<int>pre;
                    pre.push_back(i); pre.push_back(j);
                    int x1=i,y1=j;
                    q.push({i,j});
                    while(!q.empty()) {
                        int s=q.size();
                        while(s--) {
                            vector<int>k=q.front(); q.pop();
                            x1=max(x1,k[0]);
                            y1=max(y1,k[1]);
                            for(int d=0;d<4;d++) {
                                int X=k[0]+dx[d],Y=k[1]+dy[d];
                                if(X>=0 && Y>=0 && X<n && Y<m &&
                                  !vis[X][Y] && land[X][Y]) {
                                    vis[X][Y]=1;
                                    q.push({X,Y});
                                }
                            }
                        }
                    }
                    pre.push_back(x1);
                    pre.push_back(y1);
                     ans.push_back(pre);
                }
               
            }
        }
        return ans;
    }
};