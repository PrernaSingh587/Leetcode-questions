class Solution {
public:
    int shipWithinDays(vector<int>& wts, int days) {
      int i=1,j=500*5*10000;
        int ans=0;
        while(i<=j) {
            int m=(i+j)/2;
            int c=0,s=0,f=0;
            for(int k: wts) {
                if(k>m) {
                    i=m+1; f=1; break;
                }
                s+=k;
                if(s==m) {
                    c++;
                    s=0;
                } else if(s>m) {
                    c++;
                    s=k;
                }
            }
            if(f==1) continue;
            if(s>m) {
                i=m+1; continue;
            } 
            if(s) c++;
            if(c>days) {
                i=m+1;
            } else if(c<=days) {
                ans=m;
                j=m-1;
            }
        }
        return ans;
    }
};