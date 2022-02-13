class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n=nums.size(),c=0;
        stack<int>st;
        vector<int>v(n);
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums[st.top()]>=nums[i]) {
                st.pop();
            }
            if(st.empty()) v[i]=n;
            else v[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++) {
            c+=v[i]-i;
        }
        return c;
    }
};