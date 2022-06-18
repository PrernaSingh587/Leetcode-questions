class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) {
            int maxi=arr[i],top=1;
            for(int j=i;j>=max(0,i-k+1);j--) {
                maxi=max(maxi,arr[j]);
                dp[i+1]=max(dp[i+1],dp[i-top+1]+maxi*(top));
                top++;
            }
           // cout<<dp[i+1]<<" ";
        }
        return dp[n];
    }
};