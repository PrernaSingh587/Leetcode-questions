class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        int nn=pow(2,n)-1; //cout<<nn<<" ";
        for(int i=0;i<=nn;i++) {
            int x=i;
            vector<int>b;
            for(int j=n-1;j>=0;j--) {
                int k=(x>>j)&1; //cout<<k<<" ";
                if(k) {
                    b.push_back(nums[j]);
                }
            }
            v.push_back(b);
        }
        return v;
        
    }
};