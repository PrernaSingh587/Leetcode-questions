class Solution {
public:
    int max(int a,int b) {
        if(a<b) return b;
        return a;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        int maxi=0;
        for( int i : nums ) {
            int j=lower_bound(v.begin(),v.end(),i)-v.begin();
            if(j==v.size()) v.push_back(i);
            else v[j]=i;
            maxi=max(maxi,v.size());
        }
        return v.size();
    }
};