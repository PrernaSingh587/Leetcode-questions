//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int maxi=arr[0],sum=0;
	    int dp[n];
	     dp[0]=arr[0]; sum+=arr[0];
	    for(int i=1;i<n;i++) {
	        sum+=arr[i];
	        int sumMax=arr[i];
	        for(int j=i-1;j>=0;j--) {
	            if(arr[j]>=arr[i]) continue;
	            sumMax=max(sumMax,dp[j]+arr[i]);
	        }
	        dp[i] = sumMax;
	        maxi=max(maxi,dp[i]);
	    }
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends