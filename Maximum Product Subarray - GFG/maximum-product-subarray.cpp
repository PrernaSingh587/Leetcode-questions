// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    #define ll long long 
    ll min(ll g, ll f) {
        if(g<f)return g; else return f;
    }
     ll max(ll g, ll f) {
        if(g>f) return g; else return f;
    }
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    ll int maxi=arr[0],mini=arr[0],r=arr[0];
	    
	    for(int i=1;i<n;i++) {
	        if(arr[i]<0) swap(mini,maxi);
	       ll int h=mini*arr[i],k=maxi*arr[i];
	       mini=min(arr[i],h);
	       maxi=max(arr[i],k);
	       r=max(r,maxi);
	    }
	    return r;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends