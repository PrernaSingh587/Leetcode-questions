class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++) { int s=0;
            for(int j=i;j<nums.size();j++) {
                s+=nums[j];
                if(s>=t) {
                    mini=min(mini,j-i+1); break;
                }
            }
        }
        return mini==INT_MAX?0:mini;
    }
};