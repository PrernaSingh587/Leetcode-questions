class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int ans=INT_MAX;
        int l=0,s=0;
        for(int i=0;i<nums.size();i++) {
            s+=nums[i];
            while(s>=t) {
                ans=min(ans,i-l+1);
                s-=nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};