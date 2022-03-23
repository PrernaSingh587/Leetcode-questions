class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>v;
        for(int i=0;i<nums.size();i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int x=nums[i]*-1;
            int l=i+1,r=nums.size()-1;
           
            while(l<r) {
                if(nums[l]+nums[r]==x) { vector<int>p;
                    p.push_back(x*-1); 
                    p.push_back(nums[l]); 
                    p.push_back(nums[r]);
                    v.push_back(p);
                    int d=l;
                    
                    while(l<r && nums[l]==nums[d]) l++;
                    d=r;
                    
                    while(r>l && nums[r]==nums[d]) r--;
                } else if(nums[l]+nums[r]>x) {
                    r--;
                } else l++;
            }
            //if(p.size()) 
        }
        return v;
    }
};