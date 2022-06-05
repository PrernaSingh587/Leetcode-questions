class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        int maxi=0;
        unordered_map<int,int>mp;
        int dp[n][n]; memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++) {
            mp[arr[i]]=i;
            for(int j=i+1;j<n;j++) {
                int k=arr[j]-arr[i];
                if(mp.count(k)==0) continue;
                if(mp[k]<i) {
                    dp[i][j]=max(dp[i][j],1+dp[mp[k]][i]);
                    maxi=max(dp[i][j],maxi);
                }
            }
          
        }
          return maxi==0?0:maxi+2;
    }
};