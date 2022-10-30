class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=1;i<=n;i++) {x^=i;
        x^=nums[i-1];
                             } 
       // cout<<x<<" ";
        for(int i=0;i<n;i++) {
            int k=abs(nums[i]);
            if(nums[k-1]<0) {
                int p=x^k;
               // cout<<p<<" "<<k<<" ";
                return {k,x^k};
            }
            nums[k-1]*=-1;
        }
        return {};
        
    }
};