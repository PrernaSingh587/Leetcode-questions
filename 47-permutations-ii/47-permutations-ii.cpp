class Solution {
public:
    vector<vector<int>>v;
    int solve(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while((i-1)>=0 && nums[i]<=nums[i-1]) {
            i--;
        }
        //cout<<i<<" ";
        if(i==0) {
            sort(nums.begin(),nums.end());
            v.push_back(nums);
            return 1;}
        int l=i-1,m=INT_MAX,ind;
        for(;i<n;i++) {
            if(nums[i]>nums[l]) {
               if(m>nums[i]) {
                   m=nums[i];
                   ind=i;
               }
            }  
        }
          swap(nums[l],nums[ind]);
        sort(nums.begin()+l+1,nums.end());
         v.push_back(nums);
        return 0;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        while(solve(nums)==0);
        return v;
    }
};