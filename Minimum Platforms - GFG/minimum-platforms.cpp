// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int max(int a,int b) {
        return a>b?a:b;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	priority_queue<int,vector<int>,greater<int>>q;
    	multiset<pair<int,int>>st;
    	for(int i=0;i<n;i++) {
    	    st.insert({arr[i],dep[i]});
    	}
    	int maxi=0;
    	for(auto i=st.begin();i!=st.end();i++) {
    	    pair<int,int>v=(*i);
    	    while(!q.empty() && q.top()<v.first) q.pop();
    	    q.push(v.second);
    	    maxi=max(maxi,q.size());
    	}
    	return maxi;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends