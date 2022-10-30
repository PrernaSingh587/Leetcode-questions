class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++) {
            int k=abs(nums[i]);
            if(nums[k-1]<0) continue;
            nums[k-1]*=(-1);
        }
        int top=0;
        for(int i : nums) {
            if(i>0) v.push_back(top+1);
            top++;
        }
        return v;
     }
};