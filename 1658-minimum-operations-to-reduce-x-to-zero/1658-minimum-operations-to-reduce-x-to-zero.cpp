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
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i]; 
            if(mp.count(sum-s)) {
                maxi=max(maxi,i-mp[sum-s]);
            }
            mp[sum]=i;
        }
        return maxi==INT_MIN?-1:n-maxi;
    }
};