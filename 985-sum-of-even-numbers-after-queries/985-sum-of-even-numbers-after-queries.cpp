class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
         vector<int>v;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            mp[i]=nums[i];
            sum+=(nums[i]%2==0?nums[i]:0);
        }
        for(vector<int>h : q) {
            int x=h[0],y=h[1];
            int d=mp[y];
            if(d%2==0 && x%2) sum-=d;
            else if(d%2 && x%2==0) {}
            else {
                if(d%2)
                sum+=(x+d);
                else sum+=x;
            }
            d+=x;
            mp[y]=d;
        
            v.push_back(sum);
        }
        return v;
    }
};