class Solution {
public:
    int max(int a, int b) {
        return a>b ? a :b;
    }
    int minOperations(vector<int>& nums, int x) {
        unordered_map<long long,int>mp;
       int s=0,maxi=INT_MIN;
        int n=nums.size();
        for(int i :nums) s+=i;
        s-=x; if(s==0) return n;
        if(s<0) return -1;
        int sum=0,l=0;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            while(sum>s) {
                sum-=nums[l++];
            }
            if(sum==s) {
                maxi=max(maxi,i-l+1);
            }
        }
        return maxi==INT_MIN?-1:n-maxi;
    }
};