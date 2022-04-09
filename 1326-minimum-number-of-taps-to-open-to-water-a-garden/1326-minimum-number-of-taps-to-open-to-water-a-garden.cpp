class Solution {
public:
    int minTaps(int n, vector<int>& rn) {
        vector<int>v(n+1,0);
        for(int i=0;i<=n;i++) {
            int x1=max(0,i-rn[i]),x2=min(n,i+rn[i]);
             v[x1]=max(v[x1],x2-x1);
        }
       
        int c=0,r=0,maxi=0;
        for(int i=0;i<n;i++) {
            maxi=max(maxi,i+v[i]);
            if(r==i) {
                if(maxi<=r) return -1;
                c++;
                r=maxi;
            }
        }
        return c;
    }
};