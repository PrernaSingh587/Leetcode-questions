class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long int x=0;
        for(int i : nums) x^=i;
        int diff=(x&(-x));
        vector<int>v(2,0);
        for(int i=0;i<n;i++) {
            if(diff&nums[i]) {
                v[0]^=nums[i];
            } else v[1]^=nums[i];
        }
        return v;
    }
};