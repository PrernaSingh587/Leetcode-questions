class Solution {
public:
    bool validateStackSequences(vector<int>& ps, vector<int>& pp) {
        int n=pp.size(),t1=0,t2=0;
        stack<int>st;
       
        while(t1<n) {
            int m=t1;
            st.push(ps[t1]);
            while(!st.empty() && st.top()==pp[t2]) {
                st.pop();
                t2++;
            }
            t1++;
            
        }
        // while(t2<n) {
        //     if(!st.empty() && st.top()==pp[t2]) {
        //         st.pop();
        //         t2++;
        //     } else return 0;
        // }
       return t2==n;
    }
};