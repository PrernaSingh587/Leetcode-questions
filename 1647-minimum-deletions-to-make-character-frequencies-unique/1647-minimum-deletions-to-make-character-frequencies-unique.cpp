class Solution {
public:
    int minDeletions(string s) {
        int a[26]={0};
        for(char c : s) a[c-'a']++;
        map<int,int>mp;
        for(int i=0;i<26;i++) if(a[i]) mp[a[i]]++;
        int c=0;
        for(auto i=mp.rbegin();i!=mp.rend();i++) {
            int x=i->first,y=i->second;
            if(x<1) break;
            //cout<<x<<" "<<y<<endl;
            if(y==1) continue;
            c+=y-1;
            mp[x-1]+=y-1;
        }
        return c;
    }
};