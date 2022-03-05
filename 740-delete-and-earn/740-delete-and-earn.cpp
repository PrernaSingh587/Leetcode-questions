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
        return solve(maxi);
    }
};