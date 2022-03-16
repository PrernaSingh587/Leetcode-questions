class Solution {
public:
    void dfs(int k,int n,vector<int>adj[],int &c,int *vis) {
        vis[k]=1;
        c++;
        for(int j : adj[k]) {
            if(!vis[j]) 
                dfs(j,n,adj,c,vis);
        }
    }
    int maximumDetonation(vector<vector<int>>& b) {
        int n=b.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++) {
            int x1=b[i][0],y1=b[i][1],r1=b[i][2];
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                int x2=b[j][0],y2=b[j][1],r2=b[j][2];
               long long rd=pow(x1-x2,2)+pow(y1-y2,2);
               long long jj = pow(r1,2);
                if(rd<=jj) { 
                    adj[i].push_back(j);
                }
            }
        }
        int maxi=0; 
        
        for(int i=0;i<n;i++) {
            int vis[n];
            memset(vis,0,sizeof(vis));
                int c=0;
                dfs(i,n,adj,c,vis);
                maxi=max(maxi,c);
            
        }
        return maxi;
    }
};