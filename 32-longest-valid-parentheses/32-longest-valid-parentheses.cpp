class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),maxi=0;
        stack<int>q;
        q.push(-1);
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                q.push(i);
            } else {
                q.pop();
                if(q.empty()) q.push(i);
                else {
                    maxi=max(maxi,i-q.top());
                }
            }
        }
        return maxi;
    }
};