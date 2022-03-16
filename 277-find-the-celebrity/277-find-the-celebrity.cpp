/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        
        int ind[n],cnd[n]; memset(ind,0,sizeof(ind));
        memset(cnd,0,sizeof(cnd));
        int ans=-1; //,f=0;
        for(int i=0;i<n;i++) {
            ans=i;
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                if(knows(i,j)) {
                   ans=-1; break;
                }
            } 
           
            if(ans==i) break;
        }
        if(ans==-1) return -1;
       // cout<<1;
        int c=0;
        for(int i=0;i<n;i++) {
            if(i==ans) continue;
            if(knows(i,ans)) c++;
        }
        return c==n-1?ans:-1;
    }
};