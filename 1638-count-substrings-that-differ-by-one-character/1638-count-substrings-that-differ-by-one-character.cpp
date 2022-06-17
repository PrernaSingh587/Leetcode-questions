class Solution {
public:
    int countSubstrings(string s, string t) {
        int n=s.size(),m=t.size();
        
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int x=i,y=j,d=0;
                while(x<n && y<m) {
                    if(s[x]!=t[y]) d++;
                    if(d==1) ans++;
                    else if(d>1) break;
                    x++; y++;
                }
            }
        }
        return ans;
    }
};