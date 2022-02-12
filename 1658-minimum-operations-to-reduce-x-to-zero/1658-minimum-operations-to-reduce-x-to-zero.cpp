class Solution {
public:
    long long max(long long a, long long b) {
        return a>b ? a :b;
    }
    int minOperations(vector<int>& nums, int x) {
        unordered_map<long long,int>mp;
       long long int s=0,maxi=LONG_MIN;
        int n=nums.size();
        for(int i :nums) s+=i;
        s-=x; if(s==0) return n;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i]; //cout<<sum<<" ";
            if(mp.count(sum-s)) { cout<<1;
                maxi=max(maxi,i-mp[sum-s]);
            }
            mp[sum]=i;
        }
        return maxi==LONG_MIN?-1:n-maxi;
    }
};