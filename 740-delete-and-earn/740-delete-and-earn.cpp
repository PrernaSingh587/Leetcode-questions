class Solution {
public:
    unordered_map<int,int>mp,cache;
    int solve(int maxi) {
        if(maxi<=0) return 0;
        if(cache.count(maxi)) return cache[maxi];
        return cache[maxi]=max(mp[maxi]+solve(maxi-2),solve(maxi-1));
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=0;
        for(int i : nums) {mp[i]+=i; maxi=max(maxi,i); }
        int dp[maxi+1];
        dp[0]={0};
        for(int i=1;i<=maxi;i++) {
            if(i==1) {
                dp[i]=mp[i];
            } else {
                dp[i]=max(mp[i]+dp[i-2],dp[i-1]);
            }
        }
        return dp[maxi];
    }
};