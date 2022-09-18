class Solution {
public:
    int trap(vector<int>& ht) {
        int n=ht.size();
        int r[n],l[n];
        r[n-1]=ht[n-1];
        l[0]=ht[0];
        
        for(int i=n-2;i>=0;i--) {
            r[i]=max(r[i+1],ht[i]);
        }
        for(int i=1;i<n;i++) {
            l[i]=max(l[i-1],ht[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
           ans+=(min(r[i],l[i])-ht[i]); 
        }
        return ans;
    }
};