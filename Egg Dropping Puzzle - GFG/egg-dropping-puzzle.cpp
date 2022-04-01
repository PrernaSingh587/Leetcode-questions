// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int n,int k) {
        if(n<=1 || k<=1) return k;
        int ans=INT_MAX;
        if(dp[n][k]!=-1) return dp[n][k];
        for(int i=1;i<=k;i++) {
            int h=1+max(solve(n,k-i),solve(n-1,i-1));
            ans=min(ans,h);
        }
        return dp[n][k]=ans;
    }
    int eggDrop(int n, int k) 
    { memset(dp,-1,sizeof(dp));
       return solve(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends