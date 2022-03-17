class Solution {
public:
    void dfs(vector<vector<int>>& con, int n, int *vis, int k) {
        vis[k]=1;
        //cout<<k<<" ";
        int top=0;
        for(int i : con[k]) {
            
            if(top==k) { top++; continue;}
            if(i==1 && !vis[top]) dfs(con,n,vis,top);
            top++;
        }
        
    }
    int findCircleNum(vector<vector<int>>& con) {
        int n=con.size();
        int ans=0;
        int vis[n]; memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
               // cout<<endl;
                dfs(con,n,vis,i);
                ans++;
            }
        }
        return ans;
    }
};