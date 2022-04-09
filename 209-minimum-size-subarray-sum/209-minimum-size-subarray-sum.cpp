class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n=nums.size();
       
        int sum=0,top=0,mini=INT_MAX;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            while(sum>=t) {
                mini=min(mini,i-top+1);
                top++;
                sum-=nums[top-1];
            }
        }
       return mini==INT_MAX?0:mini;
    }
};