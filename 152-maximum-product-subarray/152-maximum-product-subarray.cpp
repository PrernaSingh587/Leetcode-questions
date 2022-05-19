class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        int result=INT_MIN;
        for(int i : nums) {
            prod*=i;
            result=max(result,prod);
           // cout<<result<<" ";
            if(prod==0) prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--) {
            prod*=nums[i];
            result=max(result,prod);
             //cout<<result<<" ";
            if(prod==0) prod=1;
        }
        return result;
    }
};