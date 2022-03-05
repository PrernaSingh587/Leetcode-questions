class Solution {
public:
   
    int deleteAndEarn(vector<int>& nums) {
        int sum[20001]={0};
        int dp[20001]={0};
        for(int i : nums) sum[i]+=i;
        dp[0]=0;
        dp[1]=sum[0];
        for(int i=2;i<20001;i++) {
            dp[i]=max(sum[i-1]+dp[i-2],dp[i-1]);
            //cout<<dp[i]<<" ";
        }
        return dp[20000];
    }
};