class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=0,n=s.size(),i1=0,i2=0;
        for(int i=0;i<s.size();i++) {
            int l=i,r=i,f=1;
            while(l>=0 && r<n) {
                if(s[l]!=s[r]) f=0;
                if(f) {
                    int h=maxi;
                    maxi=max(maxi,r-l+1);
                    if(h!=maxi) {
                        i1=l,i2=r;
                    }
                }
                l--; r++;
            }
            l=i,r=i+1,f=1;
            while(l>=0 && r<n) {
                if(s[l]!=s[r]) f=0;
                if(f) {
                    int h=maxi;
                    maxi=max(maxi,r-l+1);
                    if(h!=maxi) {
                        i1=l,i2=r;
                    }
                }
                l--; r++;
            }
        }
        return s.substr(i1,maxi);
    }
};