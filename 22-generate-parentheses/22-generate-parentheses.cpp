class Solution {
public:
    vector<string>ans;
    void solve(int curr,int op,int cl,string sh,int n) {
        if(op==0 && cl==0) {
            ans.push_back(sh);
            return ;
        }
        if(curr==0) {
            solve(curr+1,op,cl,sh+'(',n);
        } else if(curr<op) {
            solve(curr+1,op,cl,sh+'(',n);
            solve(curr-1,op-1,cl-1,sh+')',n);
        } else {
            solve(curr-1,op-1,cl-1,sh+')',n);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(0,n,n,"",n);
        return ans;
    }
};