class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int k=0;
        for(int i : nums) if(i==1) k=1;
        if(k==0) return 1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<=0) nums[i]=1;
        }
        for(int i=0;i<nums.size();i++) {
            int h=(abs(nums[i]));
            if((h)>nums.size() || nums[h-1]<0 ) continue;
            nums[h-1]*=(-1);
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>0) return i+1;
        }
        return nums.size()+1;
    }
};