class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();//,k=0; //,p=0;
       
        for(int i=0;i<n;i++) {
           // if(nums[i]==0) nums[i]=1;
            int k=abs(nums[i]);
            if(nums[k-1]<0) return k;
            nums[k-1]*=(-1);
        }
        
        return n;
    }
};