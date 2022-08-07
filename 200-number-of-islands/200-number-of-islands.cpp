class Solution {
public:
    int numIslands(vector<vector<char>>& g) {
        int n=g.size(),m=g[0].size();
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        int c=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(g[i][j]=='1') { c++;
                                  g[i][j]='0';
                    queue<vector<int>>q;
                    q.push({i,j});
                    while(!q.empty()) {
                        vector<int>v = q.front();
                        q.pop();
                        int x=v[0],y=v[1];
                        
                        for(int h=0;h<4;h++) {
                            int X=x+dx[h],Y=y+dy[h];
                            if(X>=0 && Y>=0 && X<n && Y<m
                              && g[X][Y]=='1') {
                                g[X][Y]='0';
                                q.push({X,Y});
                            }
                                
                        }
                    }
                }
            }
        }
        return c;
    }
};