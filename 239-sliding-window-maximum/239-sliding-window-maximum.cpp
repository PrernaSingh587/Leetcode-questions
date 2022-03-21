class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>q;
        int top=0;
        for(int i=0;i<k;i++) {
            while(!q.empty() && q.back()<nums[i]) q.pop_back();
            q.push_back(nums[i]);
        }
        vector<int>v;
        v.push_back(q.front());
        for(int i=k;i<n;i++) {
            if(nums[top]==q.front()) q.pop_front();
            while(!q.empty() && q.back()<nums[i]) q.pop_back();
            q.push_back(nums[i]);
             v.push_back(q.front());
            top++;
        }
        return v;
    }
};