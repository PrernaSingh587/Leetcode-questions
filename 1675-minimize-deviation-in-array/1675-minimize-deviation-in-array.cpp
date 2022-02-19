class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>q;
        int mini=INT_MAX;
        for(int i : nums) {
            if(i&1) {
                mini=min(mini,i*2);
                q.push(i*2);
            } else {
                mini=min(mini,i);
                q.push(i);
            }
        }
        int dev=INT_MAX;
        while(!q.empty()) {
            int h=q.top(); q.pop();
            dev=min(dev,h-mini);
            if(h%2==0) {
                q.push(h/2);
                mini=min(mini,h/2);
            } else break;
        }
        return dev;
    }
};