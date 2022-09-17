class Solution {
public:
    int numTeams(vector<int>& rt) {
        int n=rt.size();
        int ans=0;
        
        for(int i=1;i<n-1;i++) {
            int l=0,r=0;
            for(int j=0;j<=i-1;j++) {
                if(rt[j]<rt[i]) l++;
            }
            for(int j=i+1;j<n;j++) {
                if(rt[i]<rt[j]) r++;
            }
            ans+=(l*r);
            l=0,r=0;
            for(int j=0;j<=i-1;j++) {
                 if(rt[i]<rt[j]) r++;
                
            }
            for(int j=i+1;j<n;j++) {
               if(rt[j]<rt[i]) l++;
            }
            ans+=(l*r);
        }
        return ans;
    }
};