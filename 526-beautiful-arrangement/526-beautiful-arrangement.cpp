class Solution {
public:
    int seen=0;
    int dfs(int n,int pos) {
        if(pos>n) return 1;
        int res=0;
        for(int i=1;i<=n;i++) {
            int bit =1<<i;
            if((seen&bit)==0 && (!(pos%i) || !(i%pos))) {
               seen=seen^bit;
                res += dfs(n,pos+1);
                 seen=seen^bit;
                
            }
        }
        return res;
    }
    int countArrangement(int n) {
       
        return dfs(n,1);
    }
};