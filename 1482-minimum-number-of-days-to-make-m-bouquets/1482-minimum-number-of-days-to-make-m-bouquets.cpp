class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        if(b.size()<m*k) return -1;
        int r=0,l=1;
        for(int i=0;i<b.size();i++) {
            r=max(r,b[i]);
        }
        int maxi=-1;
        while(l<=r) {
            int mj=l+(r-l)/2;
           // cout<<mj<<" ";
            int c=0,num=0,h=0;
            while(h<b.size()) {
                if(b[h]<=mj) {
                    c++;
                    if(c==k) {num++; c=0;}
                } else {
                    c=0;
                }
                h++;
            }
           // cout<<num<<endl;
            if(num>=m) {
                maxi=mj;
                r=mj-1;
            } else if(num>m) {
                r=mj-1;
            } else l=mj+1;
        }
        return maxi;
    }
};