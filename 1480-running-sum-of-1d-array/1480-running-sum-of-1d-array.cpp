class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>v;
        int s=0;
        for(int i : nums) {
            s+=i;
            v.push_back(s);
        }
        return v;
    }
};