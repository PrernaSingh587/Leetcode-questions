//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int maxi=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(S1[i-1]==S2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;
                maxi=max(maxi,dp[i][j]);
            }
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends