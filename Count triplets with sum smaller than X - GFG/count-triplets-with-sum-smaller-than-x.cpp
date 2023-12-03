//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
    #define ll long long
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	  ll int ans=0;
	   sort(arr,arr+n);
	   for(int i=0;i<n-2;i++) {
	       int x=i+1,y=n-1;
	       while(x<y) {
	           if(arr[i]+(arr[x]+arr[y])>=sum) y--;
	           else {
	              int a=x,b=y-1,kk;
	              while(a<=b) {
	                  int m=(a+b)/2;
	                  if(arr[m]+arr[y]+arr[i]<sum) {a=m+1; kk=m;}
	                  else b=m-1;
	              }
	              ans=ans+(kk-x+1);
	              y--;
	           }
	       }
	   }
	   return ans;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends