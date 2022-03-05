class Solution {
public:
    vector<string>v;
    void p(string h,int op,int cl,int n) {
        
        if(op==cl && cl==n) {
            v.push_back(h);
            cout<<h<<" ";
            return ;
        }
        if(op==0) {
            p("(",op+1,cl,n);
            return ;
        }
        if(op==n) {
            p(h+')',op,cl+1,n);
            return ;
        }
         p(h+'(',op+1,cl,n);
        if(op>cl)
         p(h+')',op,cl+1,n);
    }
    vector<string> generateParenthesis(int n) {
        p("",0,0,n);
        return v;
    }
};