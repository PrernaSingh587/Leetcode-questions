class Solution {
public:
 int min(int a,int b) {
     return a<b?a:b;
 }
    int minTrioDegree(int n, vector<vector<int>>& ed) {
        int indeg[n+1];
         memset(indeg,0,sizeof(indeg));
        int adj[n+1][n+1];
        memset(adj,0,sizeof(adj));
        for(vector<int>v: ed) {
            adj[v[0]][v[1]]++;
            adj[v[1]][v[0]]++;
            indeg[v[0]]++;
            indeg[v[1]]++;
        }
        int mini=INT_MAX;
        for(int i=1;i<=n;i++) {
            if(indeg[i]<2) continue;
            for(int jk=1;jk<=n;jk++) {
                if(adj[i][jk]==0) continue;
                int j=jk;
                if(indeg[j]<2) continue;
                for(int kk=1;kk<=n;kk++) {
                     if(adj[j][kk]==0) continue;
                    int k=kk;
                    if(indeg[k]<2) continue;
                   
                        if(adj[k][i]) {
                            mini=min(mini,indeg[i]+indeg[j]
                                    +indeg[k]-6);
                        }
                    
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};