class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& g) {
        unordered_set<string>st;
        int n=g.size(),m=g[0].size();
        
        int vis[n][m]; memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && g[i][j]) {
                    queue<vector<int>>q;
                    q.push({i,j});
                    vis[i][j]=1;
                    string h="";
                    h+='('+to_string(0)+','+to_string(0)+')';
                    while(!q.empty()) {
                        int s=q.size();
                        while(s--) {
                            vector<int>k=q.front(); q.pop();
                            int x=k[0],y=k[1];
                            if((x+1)<n && !vis[x+1][y] && g[x+1][y]) {
                                h+='('+to_string(i-x-1)+','+to_string(j-y)+')';
                                vis[x+1][y]=1;
                                q.push({x+1,y});
                            }
                            if((y+1)<m && !vis[x][y+1] && g[x][y+1]) {
                                 h+='('+to_string(i-x)+','
                                     +to_string(j-y-1)+')';
                                vis[x][y+1]=1;
                                q.push({x,y+1});
                            }
                            if(x-1>=0 && !vis[x-1][y] && g[x-1][y]) {
                                 h+='('+to_string(i-x+1)+','+
                                     to_string(j-y)+')';
                                vis[x-1][y]=1;
                                q.push({x-1,y});
                            }
                            if((y-1)>=0 && !vis[x][y-1] && g[x][y-1]) {
                                 h+='('+to_string(i-x)+','+to_string(j-y+1)+')';
                                vis[x][y-1]=1;
                                q.push({x,y-1});
                            }
                        }
                    }
                   // cout<<h<<" ";
                    st.insert(h);
                }
            }
           
        }
         return st.size();
    }
};