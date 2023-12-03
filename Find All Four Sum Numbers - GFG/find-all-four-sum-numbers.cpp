//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k1) {
        int n=arr.size(),tp=0;
        vector<vector<int> >ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++) {
            if(i!=0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++) {
                if((j-1)!=i && arr[j]==arr[j-1]) continue;
                int sum=arr[i]+arr[j];
                int x=j+1,y=n-1;
                sum=k1-sum;
                while(x<y) {
                    if(arr[x]+arr[y]==sum) {
                      ans.push_back({arr[i],arr[j],arr[x],arr[y]});
                      int l=arr[x],m=arr[y];
                      while(x<y && l==arr[x]) x++;
                      while(y>x && m==arr[y]) y--;
                    } else if(arr[x]+arr[y]<sum) x++;
                    else y--;
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends