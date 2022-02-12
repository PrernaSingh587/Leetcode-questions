class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int c=0;
        int p=1,l=0;
        for(int i=0;i<nums.size();i++) {
            p*=nums[i];
            while(p>=k &&l<=i) p/=nums[l++];
             c+=i-l+1;
        }
        return c;
    }
};