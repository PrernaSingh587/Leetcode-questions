/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,vector<int>>mp;
        for(Employee* e : employees) {
             mp[e->id]=e->subordinates;
            mp[e->id].push_back(e->importance);
        }
        queue<int>q;
        q.push(id);
        int sum=0;
        while(!q.empty()) {
            int k=q.front(); q.pop();
            sum+=mp[k].back();
            for(int i=0;i<mp[k].size()-1;i++) {
                if(mp.count(mp[k][i])) q.push(mp[k][i]);
            }
            mp.erase(k);
        }
        return sum;
    }
};