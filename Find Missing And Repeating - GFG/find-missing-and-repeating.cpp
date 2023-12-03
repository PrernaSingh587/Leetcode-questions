//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
       vector<int>v(2);
       int sum=0,repeat;
       for(int i=0;i<n;i++) {
           int h=abs(arr[i]);
           sum^=(i+1);
           sum^=h;
           if(arr[h-1]<0) {
               repeat = h;
           } else
           arr[h-1]*=-1;
       }
       v[0]=repeat;
       v[1]=sum^repeat;
       return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends