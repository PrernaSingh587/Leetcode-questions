class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum=0;
        int maxi=0,l=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
            for(int i=0;i<nums.size();i++) {
                sum+=nums[i];
                if(mp.count(sum-k)) {
                    maxi=max(maxi,i-mp[sum-k]);
                }
                if(mp.count(sum)==0) mp[sum]=i; 
            }
        
        return maxi;
    }
};