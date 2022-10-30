class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n=nums.size(),k=0,p=0;
       
        for(int i=0;i<n;i++) {
            if(nums[i]==0) {
                nums[i]=1; k=1;
            }
            else if(nums[i]==1) p=1;
        }
        if(k==0) return 0;
        if(p==0) return 1;
        for(int i=0;i<n;i++) {
           // if(nums[i]==0) nums[i]=1;
            int k=abs(nums[i]);
            if(nums[k-1]<0) continue;
            nums[k-1]*=(-1);
        }
        int top=0;
        for(int i : nums) {
            if(i>0) return (top+1);
            top++;
        }
        return n;
    }
};