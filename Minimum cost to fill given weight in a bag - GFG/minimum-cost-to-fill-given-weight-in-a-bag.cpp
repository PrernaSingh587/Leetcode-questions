// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
    int dp[201][201];
    int solve(int cost[], int N, int W) {
        if(W==0) return 0;
        if(N<0) return 20000;
        if(dp[N][W]!=-1) return dp[N][W];
        if(cost[N]==-1 || N>W) {
            return dp[N][W] = solve(cost,N-1,W);
        }
        return dp[N][W] = min(cost[N]+solve(cost,N,W-(N+1)),solve(cost,N-1,W));
    }
	public:
	int minimumCost(int cost[], int N, int W) 
	{   memset(dp,-1,sizeof(dp));
	    return solve(cost,N-1,W);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends