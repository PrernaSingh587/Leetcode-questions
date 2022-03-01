class Solution {
public:
    int maxNumberOfBalloons(string t) {
        int a[26]={0};
        for(char c : t) {
            a[c-'a']++;
        }
        unordered_map<int,int>mp;
        mp[1]=1;
        mp[0]=1;
        mp['l'-'a']=2;
        mp['o'-'a']=2;
        mp['n'-'a']=1;
        int mini=INT_MAX;
        for(auto i=mp.begin();i!=mp.end();i++) {
            mini=min(mini,a[i->first]/i->second);
        }
        return mini;
    }
};