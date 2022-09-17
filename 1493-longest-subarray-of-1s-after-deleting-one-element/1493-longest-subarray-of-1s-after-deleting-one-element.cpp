class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        if(nums[0]==1)
        v.push_back(-1);
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) v.push_back(i);
        }
        if(nums[n-1]==1)
        v.push_back(n);
        
        if(v.size()==2) {
            if(v[0]==-1 || v[1]==n)
            return n-1;
            return n-2;
        }
        
        int maxi=0;
        //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        for(int i=1;i<v.size()-1;i++) {
            int l=v[i-1]+1,r=v[i+1]-1;
            maxi=max(maxi,(r-l));
        }
        return maxi;
    }
};