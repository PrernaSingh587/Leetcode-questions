class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxi=0,s=0;
        for(int i=0;i<n;i++) {
            if(nums[i]) {
                s++;
            } else {
                maxi=max(maxi,s);
                s=0;
            }
            
        }
         maxi=max(maxi,s);
        return maxi;
    }
};