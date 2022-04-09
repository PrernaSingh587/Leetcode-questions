// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int c1=0,ind2=-1,c=0,maxi=INT_MAX;
        for(int i=0;i<n;i++) {
            if(arr[i]<=k) { c++;
            }
        }
        int top=0;
        for(int i=0;i<c;i++) {
            if(arr[i]>k) c1++;
        }
        maxi=min(maxi,c1);
        for(int i=c;i<n;i++) {
            if(arr[top]>k) c1--;
            top++;
            if(arr[i]>k) c1++;
            maxi=min(maxi,c1);
        }
        return maxi;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends