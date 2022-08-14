class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        queue<vector<int>>q;
        int a=0; //,b=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(g[i][j]==2) {q.push({i,j});}
                if(g[i][j]==1) a++;
            }
        }
        if(a==0) return 0;
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        int c=0;
        while(!q.empty()) {
           int s=q.size();
            while(s--) {
                vector<int>p=q.front(); q.pop();
                int x=p[0],y=p[1];
                for(int i=0;i<4;i++) {
                    int X=x+dx[i],Y=y+dy[i];
                    if(X>=0 && Y>=0 && X<n && Y<m && g[X][Y]==1) {
                        g[X][Y]=2; a--;
                        q.push({X,Y});
                    }
                }
            }
            c++;
        }
        return a==0 ? c-1 : -1;
    }
};