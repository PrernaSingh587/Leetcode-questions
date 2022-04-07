// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
#define pp pair<int,pair<int,int>>
class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
         priority_queue<pp,vector<pp>,greater<pp>>q1;
         priority_queue<pp>q2;
         int maxi=0;
         for(int i=0;i<k;i++) {
             q1.push({a[i][0] , {i,0}}); 
             maxi=max(maxi,a[i][0]);
         }
         int mini=INT_MAX,ind1=-1,ind2=-1;
         while(!q1.empty() || !q2.empty()) {
             pp f=q1.top(); q1.pop();
            
             if(mini>(maxi-f.first)) {
                 ind1=f.first; ind2=maxi;
                 mini=maxi-f.first;
             }
             if(f.second.second!=n-1) {
                 q1.push({a[f.second.first][f.second.second+1],{f.second.first,
                     f.second.second+1
                 }});
                 maxi=max(maxi,a[f.second.first][f.second.second+1]);
             } else break;
             
         }
         return {ind1,ind2};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends