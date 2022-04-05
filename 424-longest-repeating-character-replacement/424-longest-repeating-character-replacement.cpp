class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi=0,m=0,tot=0;
        int dp[256]={0},top=0;
        for(int i=0;i<s.size();i++) {
            dp[s[i]]++;
            m=max(m,dp[s[i]]);
            tot+=1;
            while(tot-m>k) {
                dp[s[top]]--;
                top++;
                tot--;
                m=0;
                for(int ik=0;ik<256;ik++) {
                    m=max(m,dp[ik]);
                }
            }
            maxi=max(maxi,tot);
        }
        return maxi;
    }
};