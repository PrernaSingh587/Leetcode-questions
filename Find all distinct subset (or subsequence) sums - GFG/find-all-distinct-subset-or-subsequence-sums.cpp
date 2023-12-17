//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    #define pb push_back
	vector<int> DistinctSum(vector<int>nums){
	    vector<int>ans;
	    int sum=0,n=nums.size();
	    for(int i : nums) sum+=i;
	    int dp[n+1][sum+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<=n;i++) dp[i][0]=1;
	    for(int i=1;i<=n;i++) {
	        for(int j=1;j<=sum;j++) {
	            if(j>=nums[i-1]) dp[i][j]=dp[i-1][j] | dp[i-1][j-nums[i-1]];
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
	    for(int i=0;i<=sum;i++) {
	        if(dp[n][i]) ans.pb(i);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends