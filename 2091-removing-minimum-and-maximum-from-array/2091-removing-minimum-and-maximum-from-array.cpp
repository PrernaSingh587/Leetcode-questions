class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,mini=INT_MAX,m1,m2;
        for(int i=0;i<n;i++) {
            if(maxi<nums[i]) {
                maxi=nums[i];
                m1=i;
            }
            if(mini>nums[i]) {
                mini=nums[i];
                m2=i;
            }
        }
        if(m1>m2) swap(m1,m2);
       return min(m2+1 , min(n-m1 , m1+1+n-m2));
            
    }
};