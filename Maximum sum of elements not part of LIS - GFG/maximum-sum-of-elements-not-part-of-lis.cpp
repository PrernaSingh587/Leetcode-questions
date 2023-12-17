//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSumLis(int arr[], int n) {
        int dp[n][2]; memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        dp[0][1]=arr[0];
        int sum=arr[0];
        for(int i=1;i<n;i++) {
            sum+=arr[i];
            int maxi=0,sumMaxi=INT_MAX;
            for(int j=i-1;j>=0;j--) {
                if(arr[j]>=arr[i]) continue;
                if(maxi<dp[j][0]) {
                    maxi=dp[j][0];
                    sumMaxi=dp[j][1];
                } else if(maxi==dp[j][0]) {
                    if(sumMaxi > dp[j][1]) {
                        sumMaxi=dp[j][1];
                    }
                }
            }
            dp[i][0]=1+maxi; dp[i][1]=arr[i]+(sumMaxi==INT_MAX?0 : sumMaxi);
            
        }
       
        int ans=0,maxi=0;
        for(int i=0;i<n;i++) {
            if(maxi<dp[i][0]) {
                maxi=dp[i][0];
                ans=sum-dp[i][1];
            } else if(maxi==dp[i][0]) {
                if(ans < (sum-dp[i][1])) {
                    ans=sum-dp[i][1];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for (int i = 0; i < n; i++) cin >> Arr[i];
        Solution obj;
        cout << obj.maxSumLis(Arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends