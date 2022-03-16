class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        vector<string>ans;
        unordered_set<string>stt;
        for(string g : rec) stt.insert(g);
        unordered_map<string,vector<string>>mp;
        int top=0;
        unordered_map<string,int>vd;
        for(vector<string>v : ing) {
            for(string d : v) {
                mp[d].push_back(rec[top]);
                vd[rec[top]]++;
            }
            top++;
        }
        queue<string>q;
        for(string d : sup) {
            q.push(d);
        }
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                string k=q.front(); q.pop();
                if(stt.find(k)!=stt.end()) ans.push_back(k);
                for(string ss : mp[k]) {
                    vd[ss]--;
                    if(vd[ss]==0) q.push(ss);
                }
            }
        }
        return ans;
    }
};