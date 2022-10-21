class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int ind, int val) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++) {
            if(i>ind) {
                //cout<<nums[i-ind-1]<<" ";
                st.erase(nums[i-ind-1]);
            } 
            auto it = st.lower_bound(nums[i]-val);
            cout<<nums[i]-val<<" ";
            if(it!=st.end()) {
               if((*it)-nums[i]<=val)
                return 1;}
            st.insert(nums[i]);
            cout<<endl;
        }
        return 0;
    }
};