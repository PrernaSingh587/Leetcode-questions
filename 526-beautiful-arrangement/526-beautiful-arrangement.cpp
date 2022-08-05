class Solution {
public:
    int seen[16];
    int dfs(int n,int pos) {
        if(pos>n) return 1;
        int res=0;
        for(int i=1;i<=n;i++) {
            if(!seen[i] && (!(pos%i) || !(i%pos))) {
                seen[i]=1;
                res += dfs(n,pos+1);
                seen[i]=0;
            }
        }
        return res;
    }
    int countArrangement(int n) {
        memset(seen,0,sizeof(seen));
        return dfs(n,1);
    }
};