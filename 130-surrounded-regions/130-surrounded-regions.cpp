class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n=b.size(),m=b[0].size();
        queue<vector<int>>q;
        for(int i=0;i<m;i++) {
            if(b[0][i]=='O') {
                q.push({0,i});
            }
            if(b[n-1][i]=='O')  q.push({n-1,i});
        }
        for(int i=0;i<n;i++) {
            if(b[i][0]=='O') {
                q.push({i,0});
            }
            if(b[i][m-1]=='O')  q.push({i,m-1});
        }
        int dx[]={-1,1,0,0},dy[]={0,0,1,-1};
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                vector<int>v=q.front(); q.pop();
                int x=v[0],y=v[1];
                b[x][y]='*';
                for(int i=0;i<4;i++) {
                    int X=x+dx[i],Y=y+dy[i];
                    if(X>=0 && Y>=0 && X<n && Y<m 
                      && b[X][Y]=='O') {
                        b[X][Y]='*';
                        q.push({X,Y});
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(b[i][j]=='O') b[i][j]='X';
                else if(b[i][j]=='*') b[i][j]='O';
            }
        }
    }
};