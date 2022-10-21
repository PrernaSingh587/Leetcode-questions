class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return 0;
        int n=nums.size();
        unordered_set<int>mp;
        for(int i=0;i<n;i++) {
            if(i>k) {
                mp.erase(nums[i-k-1]);
            }
            if(mp.find(nums[i])!=mp.end()) return 1;
            mp.insert(nums[i]);
        }
        return 0;
    }
};