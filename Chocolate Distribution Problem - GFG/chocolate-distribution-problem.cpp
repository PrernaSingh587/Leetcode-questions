// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    #define ll long long
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
     ll mini=LONG_MAX;
     sort(a.begin(),a.end());
     mini=min(mini,a[m-1]-a[0]);
     int top=1;
     for(int i=m;i<n;i++) {
         mini=min(mini,a[i]-a[top]);
         top++;
     }
     return mini;
    }   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends