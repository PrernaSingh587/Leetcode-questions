class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++) {
            int l=i,r=i,f=1;
            while(l>=0 && r<n) {
                if(s[l]!=s[r]) f=0;
                if(f) c++;
                l--; r++;
            }
            l=i,r=i+1,f=1;
            while(l>=0 && r<n) {
                if(s[l]!=s[r]) f=0;
                if(f) c++;
                l--; r++;
            }
        }
        return c;
    }
};