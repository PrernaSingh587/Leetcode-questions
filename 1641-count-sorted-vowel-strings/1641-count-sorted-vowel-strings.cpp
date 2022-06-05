class Solution {
public:
    
    vector<int>solve(int n) {
        if(n==1) return {1,1,1,1,1};
        vector<int>v=solve(n-1),ans;
        for(int i=0;i<5;i++) {
            int sum=0;
            for(int j=i;j<5;j++) {
                sum+=v[j];
            }
            ans.push_back(sum);
        }
        return ans;
    }
    int countVowelStrings(int n) {
        vector<int>v=solve(n);
        int sum=0;
        for(int i : v) sum+=i;
        return sum;
    }
};