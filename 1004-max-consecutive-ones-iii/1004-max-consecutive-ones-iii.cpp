class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int z=0,l=0,maxi=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==0) z+=1;
            while(z>k) {
                if(nums[l]==0)
                {
                z--;}
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};