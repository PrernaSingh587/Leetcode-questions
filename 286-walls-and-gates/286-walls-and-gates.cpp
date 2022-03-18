class Solution {
public:
    void wallsAndGates(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        queue<vector<int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(g[i][j]==0) {
                    q.push({i,j});
                }
            }
        }
        int top=0;
        int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
        while(!q.empty()) {
            int s=q.size();
            top++;
            while(s--) {
                vector<int>v=q.front(); q.pop();
                for(int i=0;i<4;i++) {
                    int X=v[0]+dx[i],Y=v[1]+dy[i];
                    if(X>=0 && Y>=0 && X<n && Y<m &&
                      g[X][Y]!=-1 && g[X][Y]!=0 && g[X][Y]>top) {
                        g[X][Y]=top;
                        q.push({X,Y});
                    }
                }
            }
        }
    }
};