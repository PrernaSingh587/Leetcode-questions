class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>>obj;
        for(int i=0;i<nums.size();i++) {
            for(int j : nums[i]) obj.push_back({j,i});
        }
        vector<int>ans(2);
        sort(obj.begin(),obj.end());
        int k=nums.size();
        int l=0,c=0;
        int mini=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<obj.size();i++) {
           
            mp[obj[i][1]]++;
            if(mp[obj[i][1]]==1) c++;
            while(mp[obj[l][1]]>1 && l<=i) {
               mp[obj[l][1]]--; l++;
            } 
             //cout<<obj[i][0]<<" "<<obj[i][1]<<" "<<c<<endl;
            if(c==k && mini>(obj[i][0]-obj[l][0]+1)) { //cout<<mini<<" ";
                mini=obj[i][0]-obj[l][0]+1;
                ans[0]=obj[l][0]; ans[1]=obj[i][0];
            }
        }
        return ans;
    }
};