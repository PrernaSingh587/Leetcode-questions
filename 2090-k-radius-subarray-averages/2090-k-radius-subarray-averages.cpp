class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int kk) {
        int x,y,n=nums.size();
         if(kk>n) {
             for(int i=0;i<n;i++) nums[i]=-1;
             return nums;
         }
        vector<int>v;
        long long int sum=0,top=0;
        int k=kk*2+1;
        if(k>n) {
            for(int i=0;i<n;i++) nums[i]=-1;
             return nums;
        }
        for(int i=0;i<k;i++) {
            sum+=nums[i];
        }
        x=(k)/2-1;
        cout<<x<<" ";
        for(int i=0;i<=x;i++) v.push_back(-1);
        int i;
        x++;
        v.push_back(sum/k);
        for(i=k;i<n;i++) {
            sum-=nums[top++];
            sum+=nums[i];
            v.push_back(sum/k);
            x++;
        }
        for(i=x+1;i<n;i++) v.push_back(-1);
        return v;
    }
    
};